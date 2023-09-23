#include <iostream>
#include "Mage.hpp"
#include "Barbarian.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"

using namespace std;

int main(){
  Mage defaultMage = Mage();
  defaultMage.setName("defaultMage");
  defaultMage.setRace("ELF");
  defaultMage.setVitality(5);
  defaultMage.setArmor(3);
  defaultMage.setLevel(2);
  defaultMage.setEnemy();

   cout <<  endl;
   cout << defaultMage.getName() << " is a Level " << defaultMage.getLevel() << " " << defaultMage.getRace() << "." <<  endl;
   cout << "Vitality: " << defaultMage.getVitality() <<  endl;
   cout << "Armor: " << defaultMage.getArmor() <<  endl;
  if (defaultMage.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "School of Magic: " << defaultMage.getSchool() <<  endl;
   cout << "Weapon: " << defaultMage.getCastingWeapon() <<  endl;
   cout << "Summon Incarnate: ";
  (defaultMage.hasIncarnateSummon() == 0) ?  cout << "FALSE" :  cout << "TRUE";
   cout <<  endl;

  Mage SPYNACH("SPYNACH", "ELF", 6, 4, 4, false);
  SPYNACH.setSchool("Illusion");
  SPYNACH.setCastingWeapon("Wand");
  SPYNACH.setIncarnateSummon(true);
   cout <<  endl;
   cout << SPYNACH.getName() << " is a Level " << SPYNACH.getLevel() << " " << SPYNACH.getRace() << "." <<  endl;
   cout << "Vitality: " << SPYNACH.getVitality() <<  endl;
   cout << "Armor: " << SPYNACH.getArmor() <<  endl;
  if (SPYNACH.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "School of Magic: " << SPYNACH.getSchool() <<  endl;
   cout << "Weapon: " << SPYNACH.getCastingWeapon() <<  endl;
   cout << "Summon Incarnate: ";
  (SPYNACH.hasIncarnateSummon() == 0) ?  cout << "FALSE" :  cout << "TRUE";

   cout <<  endl;
  Scoundrel defaultScoundrel = Scoundrel();
  defaultScoundrel.setName("defaultScoundrel");
  defaultScoundrel.setRace("HUMAN");
  defaultScoundrel.setVitality(6);
  defaultScoundrel.setArmor(4);
  defaultScoundrel.setLevel(3);
  defaultScoundrel.setEnemy();

   cout <<  endl;
   cout << defaultScoundrel.getName() << " is a Level " << defaultScoundrel.getLevel() << " " << defaultScoundrel.getRace() << "." <<  endl;
   cout << "Vitality: " << defaultScoundrel.getVitality() <<  endl;
   cout << "Armor: " << defaultScoundrel.getArmor() <<  endl;
  if (defaultScoundrel.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Weapon: " << defaultScoundrel.getDagger() <<  endl;
   cout << "Faction: " << defaultScoundrel.getFaction() <<  endl;
   cout << "Disguise: ";
  (defaultScoundrel.hasDisguise() == 0) ?  cout << "FALSE" :  cout << "TRUE";

  
  Scoundrel FLEA("FLEA", "DWARF", 12, 7, 5, false);
  FLEA.setDagger("Adamant");
  FLEA.setFaction("Cutpurse");
  FLEA.setDisguise(true);

   cout <<  endl;
   cout <<  endl;
   cout << FLEA.getName() << " is a Level " << FLEA.getLevel() << " " << FLEA.getRace() << "." <<  endl;
   cout << "Vitality: " << FLEA.getVitality() <<  endl;
   cout << "Armor: " << FLEA.getArmor() <<  endl;
  if (FLEA.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Weapon: " << FLEA.getDagger() <<  endl;
   cout << "Faction: " << FLEA.getFaction() <<  endl;
   cout << "Disguise: ";
  (FLEA.hasDisguise() == 0) ?  cout << "FALSE" :  cout << "TRUE";

  Ranger defaultRanger = Ranger();
  defaultRanger.setName("defaultRanger");
  defaultRanger.setRace("UNDEAD");
  defaultRanger.setVitality(8);
  defaultRanger.setArmor(4);
  defaultRanger.setLevel(5);
  defaultRanger.setEnemy();

   cout <<  endl;
   cout <<  endl;
   cout << defaultRanger.getName() << " is a Level " << defaultRanger.getLevel() << " " << defaultRanger.getRace() << "." <<  endl;
   cout << "Vitality: " << defaultRanger.getVitality() <<  endl;
   cout << "Armor: " << defaultRanger.getArmor() <<  endl;
  if (defaultRanger.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Vector or arrows: ";
  if (defaultRanger.getArrows().size() <= 0)
  {
     cout << "NONE" <<  endl;
  }
  else
  {
    for (int x = 0; x < defaultRanger.getArrows().size(); x++)
    {
     cout << defaultRanger.getArrows()[x].quantity_ << ", " << defaultRanger.getArrows()[x].type_ << ", ";
  }
  }
   cout << "Affinities: ";
  if (defaultRanger.getAffinities().size() <= 0){
     cout << "NONE" <<  endl;
  }else{
    for (int x = 0; x < defaultRanger.getAffinities().size(); x++)
    {
     cout << defaultRanger.getAffinities()[x] << ", ";
    }
  }
   cout << "Animal Companion: ";
  (defaultRanger.getCompanion() == 0) ?  cout << "FALSE" :  cout << "TRUE";

  Ranger MARROW("MARROW", "UNDEAD", 9, 6, 5, true);
  MARROW.addArrows("Wood", 30);
  MARROW.addArrows("Fire", 5);
  MARROW.addArrows("Poison", 5);
  MARROW.addAffinity("Fire");
  MARROW.addAffinity("Poison");
  MARROW.setCompanion(true);

   cout <<  endl;
   cout <<  endl;

   cout << MARROW.getName() << " is a Level " << MARROW.getLevel() << " " << MARROW.getRace() << "." <<  endl;
   cout << "Vitality: " << MARROW.getVitality() <<  endl;
   cout << "Armor: " << MARROW.getArmor() <<  endl;
  if (MARROW.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Vector of arrows: ";
  for (int x = 0; x < MARROW.getArrows().size(); x++)
  {
    if (x == MARROW.getArrows().size() - 1){
       cout << MARROW.getArrows()[x].type_ << ", " << MARROW.getArrows()[x].quantity_;
    }else{
       cout << MARROW.getArrows()[x].type_ << ", " << MARROW.getArrows()[x].quantity_ << ", ";
    }
  }
   cout <<  endl;
   cout << "Affinities: ";
  for (int x = 0; x < MARROW.getAffinities().size(); x++)
  {
    if (x == MARROW.getAffinities().size() - 1){
       cout << MARROW.getAffinities()[x];
    }else{
       cout << MARROW.getAffinities()[x] << ", ";
    }
  }
   cout <<  endl;
   cout << "Animal Companion: ";
  (MARROW.getCompanion() == 0) ?  cout << "FALSE" :  cout << "TRUE";

  Barbarian defaultBarbarian = Barbarian();
  defaultBarbarian.setName("defaultBarbarian");
  defaultBarbarian.setRace("HUMAN");
  defaultBarbarian.setVitality(10);
  defaultBarbarian.setArmor(5);
  defaultBarbarian.setLevel(5);
  defaultBarbarian.setEnemy();

   cout <<  endl;
   cout <<  endl;
   cout << defaultBarbarian.getName() << " is a Level " << defaultBarbarian.getLevel() << " " << defaultBarbarian.getRace() << "." <<  endl;
   cout << "Vitality: " << defaultBarbarian.getVitality() <<  endl;
   cout << "Armor: " << defaultBarbarian.getArmor() <<  endl;
  if (defaultBarbarian.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Main Weapon: " << defaultBarbarian.getMainWeapon() <<  endl;
   cout << "Offhand Weapon: " << defaultBarbarian.getSecondaryWeapon() <<  endl;
   cout << "Enraged: ";
  (defaultBarbarian.getEnrage() == 0) ?  cout << "FALSE" :  cout << "TRUE" <<  endl;

  Barbarian BONK("Bonk", "HUMAN", 11, 5, 5, true);
  BONK.setMainWeapon("MACE");
  BONK.setSecondaryWeapon("ANOTHERMACE");
  BONK.setEnrage(true);

   cout <<  endl;
   cout <<  endl;
   cout << BONK.getName() << " is a Level " << BONK.getLevel() << " " << BONK.getRace() << "." <<  endl;
   cout << "Vitality: " << BONK.getVitality() <<  endl;
   cout << "Armor: " << BONK.getArmor() <<  endl;
  if (BONK.isEnemy() == 1){
     cout << "They are an enemy" <<  endl;
  }else{
     cout << "They are not an enemy" <<  endl;
  }
   cout << "Main Weapon: " << BONK.getMainWeapon() <<  endl;
   cout << "Offhand Weapon: " << BONK.getSecondaryWeapon() <<  endl;
   cout << "Enraged: ";
  (BONK.getEnrage() == 0) ?  cout << "FALSE" :  cout << "TRUE" <<  endl;
}