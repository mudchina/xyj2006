//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/yard.c

inherit ROOM;
#include <ansi.h>

string *msgs = ({
        "须菩提！一合相者，则是不可说，但凡夫之人贪著其事。\n",
        "须菩提！菩萨所作福德，不应贪著，是故说不受福德。\n",
        "若以色见我，以音声求我，是人行邪道，不能见如来。\n",
        "须菩提！若福德有实，如来不说得福德多；以福德无故，如来说得福德多。\n",
        "须菩提！于意云何？如来有肉眼不？\n",
        "如是，世尊！如来有肉眼。\n",
        "须菩提！于意云何？如来有天眼不？\n",
        "如是，世尊！如来有天眼。\n",
        "须菩提！于意云何？如来有慧眼不？\n",
        "如是，世尊！如来有慧眼。\n",
        "须菩提！于意云何？如来有法眼不？\n",
        "如是，世尊！如来有法眼。\n",
        "须菩提！于意云何？如来有佛眼不？\n",
        "如是，世尊！如来有佛眼。\n",
        "须菩提！于意云何？恒河中所有沙，佛说是沙不？\n",
        "如是，世尊！如来说是沙。\n",
     });


void create ()
{
  set ("short", "庭院");
  set ("long", @LONG

庭院里面几个家佣在忙碌着，角落里仍了一些死去的野兽，还
没有来得及拨皮，地上血迹斑斑，一旁还仍了两个尖刀，和一
个铁叉。
LONG);

  set("exits", ([
        "west" : __DIR__"zhengting",
        "north"   : __DIR__"kitchen",
        "south": __DIR__"sleeproom",
        "out" : __DIR__"gate",
      ]));
  set("outdoors","sc");
  set("objects" ,([
        __DIR__"npc/yongren" :3,
        ]));
  setup();

}

void init()
{
        add_action("do_nianjing","nianjing");
}

int do_nianjing ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("sc_can_dream");
  int j;
if (!who->query_temp("sc/taibao_seen")) return notify_fail("没人请你念经啊,你瞎搅和什么呢?\n");
  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  message_vision ("$N盘膝而坐，合掌闭目。\n",who);
  if (i >= (size/2))
  {
    message_vision ("\n$N感觉到念的经已经足够超度亡魂了。\n",who); 
 who->set_temp("sc_can_sleep",1);
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_nianjing",5,who,i);
    call_out ("finish_nianjing",j,who);
  }
  return 1;
}

void start_nianjing (object who, int i)
{
  message_vision ("\n$N念道："+msgs[i]+"\n",who); 
  who->set_temp("sc_can_dream",i+1);
}

void finish_nianjing (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N念经完毕，起身。\n",who); 
  where->add("times",1);
}
