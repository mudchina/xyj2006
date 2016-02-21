//Create By Canoe 2000.11.17
//("combat_exp")>100000||("age")>20)
// literate >80
// + dx,+ pot,+ literate
// 晚上读书的地方
inherit ROOM;
#include <ansi.h>

string *strs = ({
        " 混沌初分盘古先，太极两仪四象悬， \n",
        " 子天丑地人寅出，避除兽患有巢贤。 \n",
        " 燧人取火免鲜食，伏羲画卦阴阳前， \n",
        " 神农治世尝百草，轩辕礼乐婚姻联。 \n",
        " 少昊五帝民物阜，禹王治水洪波蠲,  \n",
        " 承平享国至四百，桀王无道乾坤颠。 \n",
        " 周室开基立帝图，分茅列土报功殊.  \n",
     });
void init();
void check_time(object where);
void dushu(object where);
void finish_dushu(object where);
     
void create()
{
set ("short", "大 唐 书 院 ");
  set ("long", @LONG

这个地方就是大唐的书院了，很多新手的读书写字都是这里   
强化(dushu)的,远远看到个牌子,上书：

                ※※※※※※※※※※※※
                ※                  ※
                ※    大 唐 书 院    ※
                ※                  ※
                ※※※※※※※※※※※※

LONG);

  set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"guozijian",
]));
  set("objects", ([ /* sizeof() == 3 */
//                  __DIR__"npc/zhangsunwuji" : 1,
                __DIR__"npc/xiucai4" : 1,

]));
  set("light_up", 1);

set("start_dushu",1);
  setup();
}

void init()
{
   remove_call_out("check_time");
   check_time(this_object());
   add_action("do_dushu", "dushu");
}

void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
   if(phase==3&&(!query("start_dushu"))) dushu(where);
   if(phase==6&&query("start_dushu")) finish_dushu(where);
   call_out("check_time",60,where);
}

void dushu(object where)
{
message("channel:chat",HIY"【太平盛世】贺知章（He zhizhang）：大唐国子监开始授课!来读书吧!\n"+NOR,users());
     where->set("start_dushu",1);
} 

int do_dushu()
{ 
     object who=this_player();
     
if (who->query("kee")<20||who->query("gin")<20) return notify_fail("读书这么用功?还是先去休息休息吧!\n");
if (!who->query("family/family_name")) return notify_fail("贺知章对你摇摇手说:暂时不收没有拜师的弟子.\n");
     if(who->is_busy())
        return notify_fail("你正忙着呢。\n");
     if(!this_object()->query("start_dushu"))
        return notify_fail("晚上才开课,还不到读书的时候呢。\n");
  //   if((int)who->query("combat_exp")<10000) return notify_fail("你的武学不够进入国子监的条件.\n");   
     if((int)who->query_skill("literate",1)>80) return notify_fail("你的读书写字已经有一定造诣了.\n"); 
     if((int)who->query("combat_exp")>100000||(int)who->query("age")>20||(int)who->query("daoxing")>100000)
        return notify_fail("你都已经成年了,不用来这里读了吧?\n");
     tell_object( who,"你低眉垂目，口中微颂："+strs[random( sizeof(strs) )] );
     who->start_busy(random(6));
     who->improve_skill(   "literate",random(  (int)( who->query("spi")+who->query("int") )  )   );
     who->add("daoxing",12);
     who->add("potential",5);
      who->receive_damage("kee",20);
       who->receive_damage("sen",20);
     tell_object(who,"你觉得自己的又了解了些世界的发展历程！\n");
     return 1;
}

void finish_dushu(object where)
{
     tell_object(where,"贺知章咳嗽两声,说道:应该下课啦,解散吧。\n");
     where->delete("start_dushu");
}

