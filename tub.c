#pragma strict_types
#include "../has.h"
inherit HASROOM + "base";
inherit "w/adinos/public/water/surface_base";

/* TUB ROOM ALIAS */
#define TUB_ALIAS ({"tub","big tub","big wooden tub","wood", \
	                "the tub","wooden tub","treated wood"})
#define GRATE_ALIAS ({"grate","iron grate","rusted grate", \
                     "rusted iron grate","a grate","the grate", \
                     "a rusted heavy-looking iron grate"})
#define PEEROUT_ALIAS ({"out","peer over tub","out of tub"})
#define SOAP_ALIAS ({"soap","soap residue"})

/* WATER ALIAS */
#define WATER_ALIAS ({"water","the water","current","slight current"})

void add_room_alias();
void add_water_alias();
void peer_out();
int climb_out(string str);


void create() {
  base::create();
  surface_base::create();
  set_outdoors(1);
  set_light(1);
  set_depth(0);
  set_short("tub filled with water");
  set_long("You are in a big wooden tub filled with water. The tub is "
             "actually quite deep, the water reaching up to just below "
             "your armpits. There is a slight current in the water.");
  set_smell("The tub smells a bit of soap.");
  set_sound("The tub is rather quiet.");
  set_search("You splash around in the water but you should probably "
             "be a bit more specific about what you want to search.");
  add_room_alias();
  add_water_alias();

  create_door("down", ([
              D_DEST:HASROOM + "uw_uw3",
              D_NAME:"rusted heavy-looking iron grate",
              D_ALIAS:GRATE_ALIAS,
              D_TYPE:CLOSED,
              D_TYPE_PEER:1,
              D_PEER_MES:({"# &0 through the bars of the grate above.@peer peers",
                           "# peers through the bars of the grate below.@"}),
              D_OPEN_STR:100,
              D_OPEN_WEAK:"The grate has rusted shut and will be "
                          "impossible to open. You would have better "
                          "luck smashing it.",
              D_QUALITY:7]));

}

void add_room_alias() {
	add_item(TUB_ALIAS,"This big wooden tub is filled almost to the rim "
	         "with water. Judging by the soap residue just below the rim, "
	         "this tub is probably used for rinsing laundry.");
	add_noget(TUB_ALIAS,"While lifting the big tub filled to the rim with "
	          "water would be a feat in itself, trying to lift it while "
	          "being in it is just impossible. Even for you.");
	add_smell(TUB_ALIAS,"The wooden tub has been treated with something, "
	          "so it smells funny.");
	add_sound(TUB_ALIAS,"You do not hear anything. Not even a faint creak.");
	add_touch(TUB_ALIAS,"It feels smooth.");
	add_taste(TUB_ALIAS,"It has been treated with something, so it tastes "
	          "funny.");
	add_search(TUB_ALIAS,"You search it thoroughly, but do not find any "
	           "hidden secrets."); 
	
	add_noget(GRATE_ALIAS,"It is completely stuck, you cannot take it.");
	add_smell(GRATE_ALIAS,"The grate is at the bottom of the tub, under "
	          "water. Good luck smelling that.");
	add_sound(GRATE_ALIAS,"You dive under the water trying to listen to "
	          "the grate. All you hear is the bubbling from the water.");
	add_touch(GRATE_ALIAS,"It is cold to the touch.");
	add_taste(GRATE_ALIAS,"The grate is at the bottom of the tub, under "
	          "water. Good luck tasting that.");
	add_search(GRATE_ALIAS,"The grate is not hiding anything from you.");
	           
  add_item(SOAP_ALIAS,"There is some soap residue just below the rim of "
           "the tub.");
  add_noget(SOAP_ALIAS,"You scratch loose some soap, it just falls down "
            "into the water and dissolves.");
  add_smell(SOAP_ALIAS,"It smells like soap alright.");
  add_sound(SOAP_ALIAS,"The soap is not telling you what you want to hear.");
  add_touch(SOAP_ALIAS,"The soap residue feels icky.");
  add_taste(SOAP_ALIAS,"It tastes like soap.");
  add_search(SOAP_ALIAS,"The soap is not hiding anything from you.");
	
	add_message("peer",PEEROUT_ALIAS,"##peer_out","peers out of the tub.");
}

void add_water_alias() {
	add_item(WATER_ALIAS,"There seems to be a slight current in the water.");
	add_noget(WATER_ALIAS,"It just escapes through your fingers.");
	add_smell(WATER_ALIAS,"You would only get water up your nose.");
	add_sound(WATER_ALIAS,"You hear the bubbling sound water is known to "
	          "make.");
	add_touch(WATER_ALIAS,"The water feels chilly.");
	add_taste(WATER_ALIAS,"The water tastes quite fresh.");
	add_search(WATER_ALIAS,"The only thing you notice is that the current "
	           "gets stronger the closer you get to the grate. Either the "
	           "water is pumped up or there is an underground river "
	           "flowing below the grate.");
}

void init() {
  base::init();
  surface_base::init();
  add_action("climb_out", "climb");
  add_action("climb_out", "leave");
}

void peer_out() {
  peer_into(HASROOM + "laundry");
  tell_room(HASROOM + "laundry",TPQN +" peers out from the tub.\n");
    
}

public void dive_below() {
  if (query_door_property("d", D_STATE) == SMASHED) {
    TP->force_us("swim down");
	} else {
	writef("You attempt a dive in this shallow water and smash your "
	      "head into the grate at the bottom of the tub.\n");
	sayf(TPQN +" dives down in the shallow tub water and knocks his head "
	    "against the grate at the bottom.\n");
	}
}

int climb_out(string str) {
  if ((int) TP->query_body_position() != 0){
  write("You must be standing first.\n");
  return 1;
  }
  if (str == "out" || str == "out of tub" || str == "tub") {
  	  write("You climb out of the tub.\n");
  	  say(TPQN +" climbs out of the tub.\n");
      TP->move_player("silent#" + HASROOM + "laundry");
      tell_room(env(TP),TPQN + " comes climbing out of the tub.\n",({TP}));
      TP->force_followers("climb out", TO);
      return 1;
   }
  notify_fail("What do you want to " + query_verb() + "?\n");
  return 0;
}