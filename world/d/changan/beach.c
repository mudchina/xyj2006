//Cracked by Roath

#include <ansi.h>

inherit ROOM;
// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

string dest=__DIR__"eastseashore";

void flood();
void _flood(object);
void strip(object);

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
        if (t>=day_phase[i]["length"])
            t -= (int)day_phase[i]["length"];
        else
            break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}


void create ()
{
  set ("short", "东海海滩");
  set ("long", @LONG

夜间的大海，海水如墨，风平浪静。月光在海面上划
出一道银光，给安静的海面增加了一丝生机。然而就
在这宁寂的表面下，海水深处暗涛汹涌，水声隆隆，
似乎要将一切生命吞噬。

LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eastseashore",
  "east" : __DIR__"beach",
]));

  setup();
  call_out("flood",21+random(20));
}

void flood() {
  object *inv=all_inventory(this_object());
  call_out("flood",21+random(20));

  tell_room(this_object(),"涨潮了，海水发出震耳欲聋的巨吼声，万马奔腾般向你扑来！\n");
  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) _flood(inv[i]);
}

void _flood(object me) {
  object corpse;
  if (!me->query("life/live_forever")) {
    message_vision("$N被潮水冲走了。\n\n",me);
    me->set_temp("death_msg","掉进东海淹死了。\n");
// strip(me);
    me->die();
    me->delete_temp("death_msg");
    corpse=present("corpse",this_object());
    if (corpse && corpse->move(dest))
        tell_room(environment(corpse),"潮水将"+corpse->name()+"冲上岸来。\n");
    return;
   }
  if (random(me->query_kar())>8) {
    message_vision("$N一提气，轻轻一跃，落在礁石上，海水呼啸着从$N脚下漫过，好险！\n\n",me);
    return;
  }
  message_vision("$N被潮水冲走了。\n\n",me);
// strip(me);
  me->unconcious();
  if (me->move(dest))
    tell_room(environment(me),"潮水将"+me->name()+"冲上岸来。\n");
}

void strip(object me) {
  object *inv=deep_inventory(me);

  me->set("water", (int)me->max_water_capacity());
  if (!inv) return;
  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) inv[i]->move(dest);
    else destruct(inv[i]);
  
}
void init() {
  int phase = NATURE_D->query_current_day_phase();
    if (phase < 6) return;
    add_action("do_fill","fill");
}

int do_fill(string arg) {
    object stone;
    object me=this_player();
  int phase = NATURE_D->query_current_day_phase();
    int r;

    if (!arg && arg!="hai" && arg!="sea") 
       return notify_fail("你要填什么？\n");

/*
    if (phase < 6) 
        remove_action("do_fill","fill");
*/
 
    if (me->is_fighting() || me->is_busy() ) {
        write("你正忙着呢。\n");
        return 1;
    }   
    if (me->query("kee")<500 || me->query("sen")<500 ||
        me->query("mana") <1000 || me->query("force")<1000) {
            write("你太累了，还是歇会儿吧。\n");
        return 1;
    }
        
  stone=present("shi kuai",me);
  if (!stone || stone->query_amount()==0)
  {
       write("你拿什么来填海啊？\n");
       return 1;
    }
    message_vision("$N从怀里掏出一块石头投入海中，石块迅速沉入水中，连水花都没激起半点。\n",me);
    // mon 7/28/99
    if(stone->query("fill_sea")) {
	write("你累得腰酸背痛，连手臂都抬不起来。\n\n");
	r=random(4)+1;
	if (r>stone->query_amount()) r=stone->query_amount();
	me->add("potential",me->query_skill("spells")/10);
    }
    stone->add_amount(-1);
    me->start_busy(3+random(3));
    return 1;
}
    
