#include "Ranger.hpp"
#include <iostream>

using namespace std;

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/

  Ranger::Ranger() : Character(){
    arrows_ = {};
    affinities_ = {};
    has_companion_ = false;
  };
/**
   Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @aram      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false
  @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
  @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
  @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
  @post       : The private members are set to the values of the corresponding parameters
  */
    Ranger::Ranger(const  string& name, const  string& race, int vitality, int armor, int level, bool enemy,  vector<Arrows> arrows,  vector< string> affinities, bool has_companion) : Character(name, race, vitality, armor, level, enemy){
    for (int i = 0; i < arrows.size(); i++){
      addArrows(arrows[i].type_, arrows[i].quantity_);
    }
    for (int i = 0; i < affinities.size(); i++){
      addAffinity(affinities[i]);
    }
      setCompanion(has_companion);
    };
    /**
      @return     : a vector of the Character's arrows
    **/
     vector<Arrows> Ranger::getArrows() const {
      return arrows_;
    };
  /**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
  **/
    bool Ranger::addArrows(const  string& type, const int& quantity){
      string caps = "";
      bool status = false;
    
      for (int i = 0; i < type.length(); i++){
        caps += toupper(type[i]);
      }
       vector< string> Arrow_Types = {"WOOD", "FIRE", "WATER", "POISON", "BLOOD"};
      for (int i = 0; i < arrows_.size(); i++){
        if (arrows_[i].type_ == caps){
          status = true;
          arrows_[i].quantity_ += quantity;
          return true;
        }
      }
      if (find(Arrow_Types.begin(), Arrow_Types.end(), caps) != Arrow_Types.end() && quantity > 0) {
        Arrows newArrow;
        newArrow.type_ = caps;
        newArrow.quantity_ = quantity;
        arrows_.push_back(newArrow);
        return true;
      }else{
        return false;
      }
    };
  /**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
                the quantity of remaining arrows in the vector is updated.
                Lowercase valid arrow types are accepted but converted to uppercase.
                If firing the last arrow, simply decrement the quantity to 0.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
  **/
    bool Ranger::fireArrow(const  string& type){
       string caps = "";
      for (int i = 0; i < type.length(); i++){
        caps += toupper(type[i]);
      }
      for (int i = 0; i < arrows_.size(); i++)
      {
        if (arrows_[i].type_ == caps && arrows_[i].quantity_ > 0){
          arrows_[i].quantity_ -= 1;
          return true;
        }
      }
      return false;
    };
  /**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
  **/
    bool Ranger::addAffinity(const  string& affinities){
       string uppercased_affinities = "";
      for (int i = 0; i < affinities.length(); i++){
        uppercased_affinities += toupper(affinities[i]);
      }
       vector< string> Affinitiy_Types = {"FIRE", "WATER", "POISON", "BLOOD"};
      if ( find(Affinitiy_Types.begin(), Affinitiy_Types.end(), uppercased_affinities) != Affinitiy_Types.end() &&  find(affinities_.begin(), affinities_.end(), uppercased_affinities) == affinities_.end()) {
        affinities_.push_back(uppercased_affinities);
        return true;
      }else{
        return false;
      }
    };
  /**
  @return     : a vector of the Character's affinities
  **/
     vector< string> Ranger::getAffinities() const {
      return affinities_;
    };
  /**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
  **/
    void Ranger::setCompanion(const bool& has_companion){
      has_companion_ = has_companion;
    };
  /**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
  **/
    bool Ranger::getCompanion() const {
      return has_companion_;
    };