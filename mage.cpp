#include "Mage.hpp"
#include <iostream>

using namespace std;

/**
  Default constructor.
  Default-initializes all private members.
  Default character name: "NAMELESS". Booleans are default-initialized to False.
  Default school of magic and weapon: "NONE".
*/
Mage::Mage() : Character()
{
  school_of_magic_ = "NONE";
  weapon_ = "NONE";
  can_summon_incarnate_ = false;
  };

  Mage::Mage(const  string& name, const  string& race, int vitality, int armor, int level, bool enemy, const  string& school_of_magic, const  string& weapon, bool can_summon_incarnate) : Character(name, race, vitality, armor, level, enemy){
    can_summon_incarnate_ = can_summon_incarnate;
    if (setSchool(school_of_magic) != true)
    {
      school_of_magic_ = "NONE";
    }
    if (setCastingWeapon(weapon) != true){
      weapon_ = "NONE";
    }
  };
  /**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
  bool Mage::setSchool(const  string& school_of_magic){
     string input_for_school = "";
    for (int x = 0; x < school_of_magic.length(); x++){
      input_for_school += toupper(school_of_magic[x]);
    }
    if (input_for_school == "ELEMENTAL"){school_of_magic_ = "ELEMENTAL";
      return true;
    }
    else if (input_for_school == "NECROMANCY"){school_of_magic_ = "NECROMANCY";
      return true;
    }
    else if (input_for_school == "ILLUSION"){school_of_magic_ = "ILLUSION";
      return true;
    }
    else{
      return false;
    }
  };
  /**
      @return  : the string indicating the character's school of magic
  **/
   string Mage::getSchool() const
  {
    return school_of_magic_;
  }
/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
    bool Mage::setCastingWeapon(const  string& weapon){
       string input_for_weapon = "";
      for (int x = 0; x < weapon.length(); x++)
      {
      input_for_weapon += toupper(weapon[x]);
      }
      if (input_for_weapon == "WAND"){weapon_ = "WAND";
        return true;
      }
      else if (input_for_weapon == "STAFF"){weapon_ = "STAFF";
        return true;
      }
      else{
        return false;
      }
    }
/**
  @return  : the string indicating the character's weapon
**/
     string Mage::getCastingWeapon() const{
      return weapon_;
    }
/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
    void Mage::setIncarnateSummon(const bool& can_summon_incarnate) {
      can_summon_incarnate_ = can_summon_incarnate;
    }
/**
  @return  : the summon-incarnate flag
**/
    bool Mage::hasIncarnateSummon() const{
      return can_summon_incarnate_;
    }