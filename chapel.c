/* Players will be able to pray for effects. */

#pragma strict_types

#include "/w/pris/def.h"
#include <room.h>
#include <body_part.h>
#include <daemons.h>

inherit "w/pris/north/rm/camp_base";

void create()
{
  ::create();
  set_short("the chapel");
  set_long("This is a small chapel that seems to be the only permanent "
  "building in the camp. Made from thick wooden planks and whitewashed, "
  "there is a peaceful feel to this chapel. A narrow aisle leads from the "
  "entrance to the small altar at the end. Hard wooden benches line both "
  "sides of the aisle.");
  set_outdoors(W_CAN_SEE);
  set_smell("The faint smell of incense permeates this chapel.");
  set_sound("The chapel is quiet and meditative.");
  remove_item(({"tent", "tents"}));
  add_all(({/*nouns*/ "chapel", "walls", "ceiling",
  "small chapel", "building", "permanent building",
  "planks", "wooden planks", "thick wooden planks", "wall",
  "wood chapel", "sturdy chapel", "ground"}),
      /*Items*/
      "The chapel has been sturdily built from wood. Thick planks "+
      "have been evenly cut and carefully put together to build "+
      "a small but sturdy and pleasant building.",
      /*Noget*/
      "The chapel is much too large and sturdy to take.",
      /*Smell*/
      "The chapel smells of incense.",
      /*Touch*/
      "The chapel feels quite rough but sturdily made.",
      /*Sound*/
      "The chapel is very quiet.");
  add_all(({"whitewash"}),
  /*Items*/ "The whitewash gives the walls a clean, fresh look.",
  /*nogets*/ "The whitewash has been painted on and cannot be "+
  "removed.",
  /*smell*/ "The whitewash smells fresh and new.",
  /*touch*/ "The whitewash feels dry and quite smooth.",
  /*sound*/ "The whitewash makes no sound.");

  add_all(({/*nouns*/"aisle", "narrow aisle", "sides" }),
      /*Items*/
      "The aisle leads from the entrance of the chapel to the altar at the "
      "end. The aisle is lined by hard wooden benches.",
      /*Noget*/
      "##base_get",
      /*Smell*/
      "##base_smell",
      /*Touch*/
      "##base_touch",
      /*Sound*/
      "##base_sound");
  add_all(({/*nouns*/"entrance", "low doorway", "doorway"}),
      /*Items*/
      "The entrance leads back out into the main camp. It is a low little "
      "doorway without a door that has been built into the chapel.",
      /*Noget*/
      "##base_get",
      /*Smell*/
      "##base_smell",
      /*Touch*/
      "##base_touch",
      /*Sound*/
      "##base_sound");
  add_all(({/*nouns*/ "altar", "small altar", "end", "wooden altar",
  "solid altar","simple altar"}),
      /*Items*/
      "This is a simple, solid, wooden altar.",
      /*Noget*/
      "The altar is much too heavy to carry.",
      /*Smell*/
      "The altar smells of sandalwood.",
      /*Touch*/
      "The altar feels solid and wooden.",
      /*Sound*/
      "##base_sound");
  add_all(({/*nouns*/ "benches", "bench", "wooden benches", "wooden bench",
  "hard wooden benches","hard bench", "hard benches", "hard wooden bench"}),
      /*Items*/
      "The benches are rough and hard. They do not seem comfortable.",
      /*Noget*/
      "The benches are too large and cumbersome.",
      /*Smell*/
      "The benches smell wooden.",
      /*Touch*/
      "The benches feel very rough.",
      /*Sound*/
      "##base_sound");
  add_chair(({"bench", "benches", "on bench", "on benches"}),
  "You sit on one of the benches. It is not very comfortable.",
  "sits on one of the benches.");
  add_bed(({"bench", "benches", "on bench", "on benches"}),
  "You lie on one of the benches. It is not very comfortable.",
  "lies on one of the benches.");
  add_exit(NROOM+"se_path", "nw");
}
void init()
{
  ::init();
  add_action("do_pray", "pray");
  add_action("do_pray", "meditate");
  add_action("do_defile", "defile");
}
int do_defile(string str)
{
  object guard;
  if(str != "chapel" &&
  str != "altar")
  {
    notify_fail("What are you trying to defile?\n");
    return 0;
  }
  else
  {
    guard = find_living("Pieter");
    if(ENV(guard) == TO) {
      write("Brother Pieter scowls deeply and you back off.\n");
      return 1;
    }
    writef("You move to defile the "+str+" of an armed camp of warrior "+
    "monks who have spent their military careers fighting Chaos and other "+
    "destructive forces.");
    writef("There is a bright flash and the altar burns with a bright "+
    "light which burns you until you pull away.");
    say(TP->query_name()+" tries to defile the "+str+".\n");
    say("The altar flashes brightly and "+TP->query_name()+" recoils "+
  "violently.\n");
    HIT_D->hit_player(TP, random(10)+10, HAND, "fire", "altar",
    "defiling an altar.");
    if(guard){
      guard->set_guarding_schedule();
    }
    return 1;
  }
}
int do_pray(string str)
{
  if(!str)
  {
    write("You "+query_verb()+" briefly at the altar of the "+
    "chapel.\n");
    say(TP->query_name()+" murmurs a brief prayer at the altar.\n");
    return 1;
  }
  return 0;
}
