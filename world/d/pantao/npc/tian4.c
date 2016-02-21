// by snowcat 5/6/1997
// tian4.c ÌìÉñ
#include "tian.h"

inherit NPC;
inherit F_SAVE;

int get_position_int ()
{
  return 4;
}

void create()
{
  set_name(get_honor_str(), ({ "tian shen", "shen", "tian" }) );
  set("title", get_respect_str());
  set("gender", "ÄĞĞÔ" );
  set("long",get_respect_str()+"¡£\n");
  set("current_player","none of us");

  setup();
}

void init()
{
  object me = this_object();

  add_action("do_save", "save");
  add_action("do_bandage","bandage");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_ji", "ji");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");
  add_action("do_bian", "bian");

  if (me->query("current_player")=="none of us")
    me->reset_me(me);    
  me->restore();
  //if (! me->restore())
  //  me->reset_me(me);
  me->fully_recover(me);
 // me->setup();

}


