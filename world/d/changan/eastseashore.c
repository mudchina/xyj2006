// Room: /changan/eastseashore.c

#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
void fly_eastsea(object me);
int do_zuo(string arg);
int do_dive();
void reset();


void create ()
{
  set ("short", "东海之滨");
  set ("long", @LONG

面前便是东海，茫茫大海望不到边际。海面上波涛汹涌，几丈
高的浪头此起彼伏，象是要吞灭一切敢于到海上的东西。也许
这里便是路的尽头，面前的大海对一个凡人来说是不可逾越的。
离岸不远处漂着一只木筏(mufa)。
LONG);

  set("objects", ([
   __DIR__"npc/jingwei":1,
  ]));
  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "一只木筏，以几根大圆木捆成。你不禁想坐(zuo)上去试一试。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"seashore2",
  "up" : __DIR__"fish",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
    object me;
    me=this_player();

   if ((sizeof(me->query_temp("wzg")))==8)
	   {
       		me->set_temp("baxian_arrive",1);
			remove_call_out("fly_eastsea");
			call_out("fly_eastsea",1,me);
	       return;
	   }

	add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
    add_action("do_dive", "dive");
}

void fly_eastsea(object me)
{
	object *baxian;    //这里用的是另外一种判断方式,确定 environment 的物件
	int i;
          baxian = all_inventory(environment(me));
		  for (i = 0;i <sizeof(baxian);i++)
          {
             if(baxian[i]->query("id")=="tieguai li")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="cao guojiu")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="lan caihe")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="han xiangzi")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="han zhongli")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="he xiangu")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="zhang guolao")
				  me->add_temp("baxian_arrive",1);
			  if(baxian[i]->query("id")=="lu dongbin")
				  me->add_temp("baxian_arrive",1);       
		  }
	if( me->query_temp("baxian_arrive")<=8 ) return;
   for (i = 0;i<sizeof(baxian);i++)
	{
	   if (!userp(baxian[i]))
	   {
	   	   destruct(baxian[i]);
	   }
	}
   message_vision("\n\n八仙再次来到东海边，仿佛回到了那些无忧无虑快乐的日子，高兴得各施仙法踏上了云层．\n\n"NOR, me);
   me->delete_temp("baxian_arrive");
   me->set("fangcun/panlong_wzg_baxian","done");
   me->start_busy(60);
   me->move("/d/sea/onsea");
   call_out("fly_eastsea1",2,me);
}

void fly_eastsea1(object me)
{
   message_vision(HIC"\n\n\n好个八仙过东海，风清清，白鹭戏晴空，浪滔滔，金龙游碧海．一行人谈笑饮酒，好不快活！\n\n"NOR, me);
   call_out("fly_eastsea2",5,me);
}

void fly_eastsea2(object me)
{
   message_vision(HIB"\n天色渐渐暗了下来，八仙仍意尤未尽．\n"NOR, me);
   call_out("finish1",3,me);
}

void finish1(object me)
{
   message_vision(WHT"\n\n\n张果老摇头晃脑道：" + RANK_D->query_respect(me) + "我们这就要回五庄观去了．\n\n"NOR, me);
   message_vision(HIY"\n\n吕洞宾拱手抱拳道：" + RANK_D->query_respect(me) + "一番美意，我这里只有再三谢过了．\n\n"NOR, me);
   call_out("finish2",3,me);
}

void finish2(object me)
{
	message_vision(HIM"\n\n何仙姑微笑着对$N道：" + RANK_D->query_respect(me) + "如此热心助人，他日必有好报．\n\n"NOR, me);
   message_vision("\n\n蓝采和点头称道：" + RANK_D->query_respect(me) + "确是有福之人．\n\n"NOR, me);
   call_out("finish3",3,me);
}

void finish3(object me)
{
	message_vision(HIW"\n\n汉钟离扇着蒲扇道：" + RANK_D->query_respect(me) + "了我八仙心愿，我等当真感谢之至．\n\n"NOR, me);
   message_vision(YEL"\n\n韩湘子横过玉笛道：" + RANK_D->query_respect(me) + "临别一曲，送知己，就当韩湘子代八仙谢" + RANK_D->query_respect(me) + "．\n\n"NOR, me);
   message_vision(YEL"韩湘子轻快的笛声在东海上阵阵传开了去，让人听了心胸顿时开阔，烦恼忧愁一扫而光．\n\n"NOR, me);
   call_out("finish4",3,me);
}

void finish4(object me)
{
	message_vision(MAG"\n\n曹国舅用白玉板打着拍子合着笛声高唱：君应有语，渺万里层云．千山暮雪，只影向谁去？\n\n"NOR, me);
   message_vision(HIG"\n\n铁拐李开怀大笑道：" + RANK_D->query_respect(me) + "八仙这就告辞了，后会有期！\n\n"NOR, me);
   call_out("finish5",2,me);
}
void finish5(object me)
{
	message_vision(HIC"\n$N连忙拱手还礼道：各位后会有期，告辞，告辞．\n\n\n"NOR, me);
   message_vision("说完，八仙便齐驾祥云往五庄观飞去，$N也落下云头回到了东海海边．\n\n"NOR, me);
   me->start_busy(1);
	me->move("/d/changan/eastseashore");
}
 
void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "一只木筏从海上漂了过来。\n", this_object() );
                message("vision", "木筏一震，显然是搁浅了。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "木筏正漂向岸边，看样子还得耐心地等等。\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "木筏已经靠岸了，随时都可上去。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "一个浪头打来，木筏向海上漂去。\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "周围是白茫茫的一片汪洋，已经看不到任何陆地的迹象了...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"aolaiws");
        message("vision", "木筏一震，搁浅了。显然是到陆地了，赶紧上去吧。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","一个浪头打来，木筏向海上漂去。\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="木筏")){ 
        message_vision("$N试着想坐上木筏。\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("你要坐上什么？\n");
}

int do_dive()
{       object me, zhou;
    object ridee;
        me=this_player();
   ridee=me->ride();



	    if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="张")
		&& (string)me->query("family/family_name")!="龙宫"
		&& (string)me->query("family/family_name")!="东海龙宫")

		return notify_fail("你一个猛子扎到水里．．．\n"+
		  "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");
                 if ( me->is_busy() )
                      return notify_fail("你一个猛子扎到水里。。。\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");
  me->start_busy(1);

   if (ridee && ridee->query("under_water")) {
     message_vision(HIY"$N一拍$n的头，连人带马跃入水中。\n"NOR,me,ridee);
     ridee->move("/d/sea/under1");
  }

      else  message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
                me->move("/d/sea/under1");
		message_vision("$N潜了过来。\n",me);
                return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}

