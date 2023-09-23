#include "Barbarian.hpp"
#include <iostream>

using namespace std;

/**
  Default constructor.
  Default-initializes all private members. Default character name: "NAMELESS".
  Booleans are default-initialized to False.
  Default weapons: "NONE".
*/

Barbarian::Barbarian() : Character()
{
  main_weapon_ = "NONE";
  secondary_weapon_ = "NONE";
  enraged_ = false;
   };
  /**
    Parameterized constructor.
    @param      : The name of the character (a const string reference)
    @param      : The race of the character (a const string reference)
    @param      : The character's vitality (an integer). Default to 0
    @param      : The character's max armor level (an integer). Default to 0
    @param      : The character's level (an integer). Default to 0
    @param      : A flag indicating whether the character is an enemy. Default to false
    @param      : The character's main weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : The character's offhand weapon (a const string reference). 
                  String inputs can be in lowercase, but must be converted to uppercase 
                  when setting the variable. Only alphabetical characters are allowed.
                  Default to "NONE"
    @param      : A flag indicating whether the character is enraged. Default to false
    @post       : The private members are set to the values of the corresponding parameters. 
                : If the main and secondary weapons are not provided or invalid, the variables                    are set to "NONE".
  */

 //may or may not work if changing both main and secondary weapons to non-const and non-reference in constructor params
   Barbarian::Barbarian(const  string& name, const  string& race, int vitality, int armor, int level, bool enemy, const  string& main_weapon, const  string& secondary_weapon, bool enraged) : Character(name, race, vitality, armor, level, enemy){

      setMainWeapon(main_weapon);
      setSecondaryWeapon(secondary_weapon);
      setEnrage(enraged);
      enraged_ = enraged;
   };
  /**
    @param    : a reference to a string representing the Character's main weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
                If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
  **/
    bool Barbarian::setMainWeapon(const  string& main_weapon){
      bool status = true;
       string caps = "";
      for (int i = 0; i < main_weapon.length(); i++){
      caps += toupper(main_weapon[i]);
      if (isalpha(toupper(main_weapon[i])) == false){status = false;}
      }
      if (status == false){
        return false;
      }
      main_weapon_ = caps;
      return true;
    };
  /**
    @return   : a string of the Character's main weapon
  **/
     string Barbarian::getMainWeapon() const{
      return main_weapon_;
    };
  /**
    @param    : a reference to a string representing the Character's secondary weapon
    @post     : sets the private member variable to the value of the parameter. 
                Only alphabetical characters are allowed.
                String inputs can be in lowercase, but must be converted to uppercase when 
                setting the variable.
              : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return   : true if setting the variable was successful, false otherwise.
  **/
    bool Barbarian::setSecondaryWeapon(const  string& secondary_weapon){
      bool status = true;
       string caps = "";
      for (int i = 0; i < secondary_weapon.length(); i++){
      caps += toupper(secondary_weapon[i]);
      if (isalpha(toupper(secondary_weapon[i])) == false){status = false;}
      }
      if (status == false){
        return false;
      }
      secondary_weapon_ = caps;
      return true;
    };
  /**
   @return    : a string of the Character's secondary weapon
  **/
     string Barbarian::getSecondaryWeapon() const {
      return secondary_weapon_;
    };
  /**
  @param      : a reference to a bool
  @post       : sets the private member variable to the value of the parameter.
  **/
    void Barbarian::setEnrage(const bool& enraged){
      enraged_ = enraged;
    };
  /**
  @return  : a boolean of whether the Character is enraged
  **/
    bool Barbarian::getEnrage() const {
      return enraged_;
    };
  /**
  @post   : sets the enraged variable to the opposite of what it was
  **/
    void Barbarian::toggleEnrage(){
      if (enraged_ != true)
      {
        enraged_ = true;
      }
      else
      {
        enraged_ = false;
      }
    }