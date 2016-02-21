// by snowcat 10/05/1997
// wu??.c 武进士

inherit NPC;
inherit F_SAVE;

#include "wu.h"

int get_category_int ()
{
  return 5;
}

int get_position_int ()
{
  return 1;
}

void create()
{
  set_name("武进士", ({ "jin shi", "jin", "shi" }) );
  set("title", get_respect_str());
  set("gender", "男性" );
  set("long",get_respect_str()+"。\n");
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
  me->fully_recover(me);
//  me->setup();

}


