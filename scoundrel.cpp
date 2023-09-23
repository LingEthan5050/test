#include "Scoundrel.hpp"
#include <map>
#include <iostream>


using namespace std;



  /**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
  */

    Scoundrel::Scoundrel() : Character(){
      has_disguise_ = false;
      dagger_ = WOOD;
      faction_ = "NONE";
    };
 /**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false.
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
  */
    Scoundrel::Scoundrel(const  string& name, const  string& race, int vitality, int armor, int level, bool enemy, const  string& dagger, const  string& faction, bool has_disguise) : Character(name, race, vitality, armor, level, enemy){
      setDagger(dagger);  
      setFaction(faction);
      setDisguise(has_disguise);
    };
  /**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
  **/
    void Scoundrel::setDagger(const  string& dagger){
       string caps = "";
      for (int i = 0; i < dagger.length(); i++){
         caps += toupper(dagger[i]);
      }
       map<string, Dagger> daggerMap;
      daggerMap["WOOD"] = WOOD;
      daggerMap["BRONZE"] = BRONZE;
      daggerMap["IRON"] = IRON;
      daggerMap["STEEL"] = STEEL;
      daggerMap["MITHRIL"] = MITHRIL;
      daggerMap["ADAMANT"] = ADAMANT;
      daggerMap["RUNE"] = RUNE;
      auto findDagger = daggerMap.find(caps);
      if (findDagger != daggerMap.end())
      {
        this->dagger_ = findDagger->second;
      }
      else {
          this->dagger_ = WOOD;
      }
    }
  /**
  @return     : the string indicating the character's dagger type
  **/
     string Scoundrel::getDagger() const {  
       map<Dagger,  string> daggerMap;
      daggerMap[WOOD] = "WOOD";
      daggerMap[BRONZE] = "BRONZE";
      daggerMap[IRON] = "IRON";
      daggerMap[STEEL] = "STEEL";
      daggerMap[MITHRIL] = "MITHRIL";
      daggerMap[ADAMANT] = "ADAMANT";
      daggerMap[RUNE] = "RUNE";
      // Find the corresponding string in the map
      auto result = daggerMap.find(this->dagger_);
      if (result != daggerMap.end()) {
        return result->second;
      }else{
        return "WOOD";
      }
    };
  /**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                 caps when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
  **/
    bool Scoundrel::setFaction(const  string& faction){
       string caps = "";
      for (int i = 0; i < faction.length(); i++){
         caps += toupper(faction[i]);
      }
      if (caps == "NONE"){
        faction_ = "NONE";
        return true;
      }
      else if (caps == "CUTPURSE"){
        faction_ = "CUTPURSE";
        return true;
      }
      else if (caps == "SHADOWBLADE"){
        faction_ = "SHADOWBLADE";
        return true;
      }
      else if (caps == "SILVERTONGUE"){
        faction_ = "SILVERTONGUE";
        return true;
      }
      else{
        return false;
      }
    };
  /**
    @return  : the string indicating the character's Faction
  **/
     string Scoundrel::getFaction() const {
      return faction_;
    };
  /**
    @param  : a reference to boolean
    @post   : sets the private member variable indicating whether the character has a disguise
  **/
    void Scoundrel::setDisguise(const bool& has_disguise){
      has_disguise_ = has_disguise;
    }
  /**
    @return  : the disguise flag
  **/
    bool Scoundrel::hasDisguise() const {
      return has_disguise_;
    };