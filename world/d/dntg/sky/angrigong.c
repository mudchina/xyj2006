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
  set ("short", "昂日宫");
  set ("long", @LONG

你走进了一间空荡荡的宫殿，只见两边站满了罗汉好象每一个罗汉都
对你怒目而视，你吓的躲到了浪翻云的雕象後面，你突然发现他的後
背上有一个按钮，你试着按了一下，突然你脚下一空，原来是个陷井，
你往下一瞧，不禁大喜，原来底下有水，你噗通一声扎入水中，正想
游上岸，不料左腿剧痛，你回头一看差点吓的昏了过去，原来一柄血
刀不知怎样插入了你的腿，将你钉在了湖中。混乱之中你好象摸到了
什麽。你拿起来一看竟然是一个骷髅头，突然从骷髅头中射出一片腿
骨，深深的插入了你的额头，你大叫一声从梦中醒了过来，全身冷汗。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"loujingong",
  "southeast" : __DIR__"kuimugong",
  "northeast" : __DIR__"weitugong",

]));


  set("objects", 
      ([
       __DIR__"stars/lfy" : 1,
      ]));


  setup();
}
 
