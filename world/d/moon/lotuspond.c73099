
#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
int do_dive();
void reset();

void create ()
{
  set ("short", "湖边");
  set ("long", @LONG

湖面绿波上飘着一叶小舟，一个绿衫少女手执双桨，缓缓划水而来，口中
唱着小曲，听那曲子是：“采莲人语隔秋烟，波静如横练。入手风光莫流
转，共留连，画船一笑春风面。江山信美，终非吾土，问何日是归年？”
歌声娇柔无邪，却有一丝淡淡的的伤感。两滩上衰草残菱(lotus)，更助秋
意。对岸烟雾缭绕，看不清有些什么。据说那里是月宫的禁地。不少人乘
船(yell boat)过去后，就再也没有回来。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "lotus" : "荷花已经谢了，莲梗上孤零零的吊着莲蓬。

",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chimeng" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"rain",
]));

  setup();
}

void init()
{
  add_action("do_cai", "cai");
  add_action("do_zuo", "yell");

}

int do_cai(string arg)
{
  object me=this_player();
  object m; 

  if( (!arg) || !((arg == "lotus") || (arg == "lian")))
    return notify_fail("采什么？\n");
  message_vision("$N见那莲蓬诱人，便伸手去摘．\n", me);
 if (me->query("kee") < (int)(me->query("max_kee")/3))
        return notify_fail("您先歇歇吧，别那么馋:)\n");

 else if (random(6) < 1){
        message_vision("$N脚下一滑，扑通一声掉进了莲花池．\n",me);
        me->move(__DIR__"hudi");
        return 1;
        }
  else if (me->query("gender") == "男性")
        return notify_fail("你突然意识到采莲不免有失英雄本色，不禁又把手缩了回来\n");  
  else{
        if ((int)me->query_skill("moondance", 1)< 60){
          me->improve_skill("moondance", 40-me->query("str"));
           message_vision(
                 "$N试着运用所学的轻功纵身跳上荷叶，发现不妙又赶紧跳了回来．\n", me);   
          tell_object(me, "你领悟出一些冷月凝香舞的技巧。\n");
          this_player()->start_busy(1);
        }
      else
        {
          message_vision("$N双脚在莲叶上一点，身子轻轻在水上掠过，回来时手中已多了一只莲蓬。\n", me);
          if(sizeof(all_inventory(this_player()))>30)
              tell_object(me,"可是你身上已经装不下了。\n");
          else {
            m = new(__DIR__"obj/lianzi.c");
            m->move(this_player()); 
            this_player()->start_busy(1);
          }
        }
        }
       me->receive_damage("kee", 20);
        return 1;
}



void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"boat")) )
            room = load_object(__DIR__"boat");
        if( room = find_object(__DIR__"boat") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"boat");
                room->set("exits/out", __FILE__);
                message("vision", "绿衫少女悠闲地把船摇到了岸边。\n", this_object() );
                message("vision", "船靠岸了。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "船正向对岸摇去，看样子还得耐心地等等。\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "小舟正靠在岸边，随时都可上去。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "绿衫女子手中竹篙在岸边轻轻一撑，小舟箭一般向湖心划去。\n",
        this_object() );

    if( room = find_object(__DIR__"boat") )
    {
        room->delete("exits/out");
        message("vision", "周围是白茫茫的一片湖水，已经离岸很远了...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"boat") )
    {
        room->set("exits/out", __DIR__"quest/enter");
        message("vision", "小船靠岸了，赶紧上去吧。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"boat") ) {
        room->delete("exits/out");
        message("vision","绿衫女子手中竹篙在岸边轻轻一撑，小舟箭一般向湖心划去。\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( arg=="boat" ){ 
        message_vision("$N对着在湖心荡舟的绿衣少女喊道：“麻烦姐姐渡我过去，感激不尽。”\n", this_player());
        check_trigger();
        return 1;
    }
    else {message_vision("$N对着湖心纵声长啸：“"+arg+"”\n",this_player());return 1;}
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"boat") )
        room->delete("zuo_trigger"); 
}

int valid_leave(object who,string dir) {

  if (dir!="enter") return 1;
  if (!present("chi meng",this_object())) return 1;
  if (who->query("daoxing")<1000000 && who->query("family/family_name")=="月宫")
    return notify_fail("痴梦仙姑一把拉住了你：“你道行太低，小心跌进湖里淹死。”\n");
  return 1;
}

