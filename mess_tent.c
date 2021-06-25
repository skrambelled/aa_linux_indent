#pragma strict_types
#include "/w/pris/def.h"
#include <room.h>

inherit "w/pris/north/rm/camp_base";

void create()
{
  ::create();
  set_short("a mess tent");
  set_long("This is the camp mess tent. Long wooden tables, flanked by hard "
  "benches fill the tent. The ground has been covered by planks, preventing "
  "dust from being kicked up by the large crowds of hungry soldiers who "
  "pack in here for meals.");
  set_outdoors(W_CAN_SEE);
  set_smell("The mess tent smells of roasted meats and a variety of "+
      "delicious foods.");
  add_all(({/*nouns*/"tent", "walls", "wall",
  "mess tent", "camp", "camp mess", "camp mess tent",
  "here", "large tent", "canvas", "canvas tent", "large canvas tent"}),
      /*Items*/
      "The mess tent is a large canvas tent that is used to house "+
      "the camp soldiers while they eat.",
      /*Noget*/
      "The mess tent is much too large for you to get.",
      /*Smell*/
      "The mess tent smells of roasted meats and a variety of "+
      "delicious foods.",
      /*Touch*/
      "The canvas tent feels rough to touch.",
      /*Sound*/
      "You cannot really make out any sounds.");
  add_all(({/*nouns*/"ground", "planks", "plank"}),
      /*Items*/
      "The planks have been placed along the ground to prevent "+
      "dirt being kicked around while people are trying to eat.",
      /*Noget*/
      "The planks have been solidly nailed together.",
      /*Smell*/
      "The planks smell like treated wood.",
      /*Touch*/
      "The planks feel splintery and coarse.",
      /*Sound*/
      "##base_sound");
  add_all(({/*nouns*/"table", "tables", "wooden tables",
  "large wooden tables"}),
      /*Items*/
      "The tables are solid affairs that are long and well built.",
      /*Noget*/
      "The tables are too large for you to carry around.",
      /*Smell*/
      "The tables smell like wood.",
      /*Touch*/
      "The tables have been sanded smooth.",
      /*Sound*/
      "##base_sound");
  add_all(({/*nouns*/ "benches",
  "bench", "hard benches", "hard bench"}),
      /*Items*/
      "The benches have been provided to allow the soldiers a "+
      "space to sit as they eat.",
      /*Noget*/
      "The benches are all too large and cumbersome.",
      /*Smell*/
      "The benches smell like wood.",
      /*Touch*/
      "The benches have been sanded smooth.",
      /*Sound*/
      "##base_sound");
  add_chair(({"bench", "benches", "on bench",
  "on benches"}),
  "You sit on one of the hard wooden benches.",
  "sits on one of the hard wooden benches.");
  add_exit(NROOM+"cook", "n");
  add_exit(NROOM+"firepit", "sw");
}
