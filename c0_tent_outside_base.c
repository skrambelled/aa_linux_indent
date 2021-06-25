#pragma strict_types
#include "../def.h"
#include <room.h>
inherit ROOM"a0_special_generic_base";

void create() {
  ::create();

  set_outdoors(W_FULL);
  set_short("outside a tent");
  set_long("A tent encompasses most of this area. The tent is largely "
           "comprised of mammoth skins, and seems to be owned by someone "
           "that has a general disregard for its overall maintenance. "
           "You can enter the tent from here.");

  add_senses(({"ground", "dirt", "grass", "area"}), ([
    "item": "You examine the ground and notice a tent nearby.",
    "noget": "You take some of the ground and then toss it away.",
    "search": "You search the ground and notice a tent nearby.",
    "smell": "You smell the ground and detect the scent of mammoth skins.",
    "sound": "You listen to the ground and hear a grunt nearby.",
    "taste": "You taste the ground and dislike the earthy tang.",
    "touch": "You touch the ground and notice a tent nearby."
  ]));

  add_senses(({"mammoth skins", "mammoth skin", "skins", "skin"}), ([
    "item": "You examine the skins and marvel at their huge size.",
    "noget": "You try to take the skins, but they do not budge.",
    "search": "You search the skins, but discover no secrets.",
    "smell": "You smell the skins and admire the leathery scent.",
    "sound": "You listen to the skins and hear a grunt nearby.",
    "taste": "You taste the skins and dislike the leathery tang.",
    "touch": "You touch the skins and admire the leathery feel."
  ]));

  add_senses(({"tent", "shelter", "walls", "wall", "roof"}), ([
    "item": "You examine the tent and admire the mammoth skins.",
    "noget": "You try to take the tent, but it does not budge.",
    "search": "You search the tent, but discover no secrets.",
    "smell": "You smell the tent and admire the leathery scent.",
    "sound": "You listen to the tent and hear a grunt nearby.",
    "taste": "You taste the tent and dislike the leathery tang.",
    "touch": "You touch the tent and admire the leathery feel."
  ]));
}
