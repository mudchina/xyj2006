// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "朱雀殿");
  set ("long", @LONG

走入朱雀殿，只见殿外蹲着两个大石狮子，三间兽头大门，
正门五间，上面桶瓦泥鳅脊，那门栏窗棱,皆是描龙飞凤，
一色水磨群墙，下面白石台矶，凿成西番草花样.左右一望，
皆雪白粉墙,下面虎皮石,随势砌去，果然气势非凡。门前
列坐着几个威风凛凛的护殿官。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"zhangyuegong",
  "north"     : __DIR__"xuanyuantang",

]));



  set("objects", 
      ([
       __DIR__"npc/hgweishi" : 4,
      ]));


  setup();
}
 
