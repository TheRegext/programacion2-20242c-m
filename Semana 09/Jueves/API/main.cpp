#include <iostream>
#include "HttpClient.h"
#include "json.hpp"
using namespace std;

class Fruta{
private:
  int _id;
  string _name;
  float _protein;
public:
  Fruta(const nlohmann::json &data){
    _id = data["id"].get<int>();
    _name = data["name"].get<string>();
    _protein = data["nutritions"]["protein"].get<float>();
  }
  
  Fruta(){
    _id = 0;
    _name = "";
    _protein = 0.0f;  
  }
  Fruta(int id, string name, float protein){
    _id = id;
    _name = name;
    _protein = protein;  
  }
  
  void setID(int id){
    _id = id;
  }
  
  int getID(){
    return _id;
  }
  
  void setName(string name){
    _name = name;
  }
  
  string getName(){
    return _name;
  }
  
  void setProtein(float protein){
    _protein = protein;
  }
  
  float getProtein(){
    return _protein;
  }
  
  string toCSV(){
    string texto;
    
    texto = to_string(_id) + ", " + _name + ", " + to_string(_protein);
    
    return texto;
  }
  
  
};


int main()
{
    HttpClient cliente;
    string response;
    nlohmann::json data;
    Fruta fruta;
    
    response = cliente.get("https://www.fruityvice.com/api/fruit/all");
    
    data = nlohmann::json::parse(response);
    
    for(int i =0; i<data.size(); i++){
      fruta = Fruta(data[i]);  
      cout << fruta.toCSV() << endl;
    }
    
    /*
    for(nlohmann::json &f : data){
      fruta = Fruta(f);  
      cout << fruta.toCSV() << endl;
    }
    */
    
    
    
    
    // cout << data["name"].get<string>() << endl;
    
    
    
    return 0;
}
