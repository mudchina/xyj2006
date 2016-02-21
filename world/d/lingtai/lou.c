//by take
#include <ansi.h>

inherit ROOM;
int do_qiansi();


void create()
{
  set ("short", "小室");
  set ("long", @LONG

这里是经阁中的一间小室，为弟子们研读经书提供了一个安静个
地方．墙上挂着一个条幅，写着＂潜思入定＂四个龙飞凤舞的大
字．据说曾经有位悟性极高的前辈每日在此潜思, 一日突然见到
八条巨龙盘旋于空中翻云吐雾, 竟从中悟出了千均棒法的真髓.

LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"jingge",
]));
        set("no_clean_up", 0);
        setup();
   //     replace_program(ROOM);
}

void init()
{
        add_action("do_qiansi", "qiansi");
}

int do_qiansi()
{
	object me;
    me=this_player();
if (((string)me->query("family/family_name")!="方寸山三星洞")&&(!wizardp(me)))
    return notify_fail("不是灵台弟子,潜思入定也没有用处！\n");

	if (me->is_busy() || me->query_temp("pending/exercising")|| me->query_temp("pending/meditating")||me->is_fighting())
    return notify_fail("你正忙着呢,急什么！\n");

  	if (me->query("fangcun/panlong_qiansi_finish")==1)
	{
         message_vision(HIW"$N盘腿坐下，合眼潜思！运起小无相功,只觉得耗去的真气又渐渐聚回丹田.\n"NOR,me);
         if (me->query("force")>=me->query("max_force")*2)
              return 1;
		 me->add("force",(random(me->query_skill("wuxiangforce")))*4+100);
         me->start_busy(10);
		 return 1;
	}
	
	if (!me->query("fangcun/panlong_qiansi"))
	{
		set("start",1);
		me->set("fangcun/panlong_qiansi",1);
	}

	if (query("start")==1)
    {

		me->add("fangcun/panlong_qiansi",1);
		set("start",0);
		call_out("add_qiansi",3600);
	}
	
	me->start_busy(random(me->query("int")));

   message_vision(HIW"$N盘腿坐下，合眼潜思！\n"NOR,me);
     
           if ((me->query("fangcun/panlong_qiansi")>=(me->query_skill("qianjun-bang"))/8)&&(me->query("family/generation")<3))
	{
		me->set("fangcun/panlong_qiansi_finish",1);
		if (random(me->query("int"))<18)
		{
			call_out("finish_qiansi2",5);
			return 1;
		}

       
	call_out("finish_qiansi",5);
    
	}  
    
   return 1;
}


void add_qiansi()
{
	remove_call_out("add_qiansi");
	set("start",1);
    return;
}

void finish_qiansi()
{
	object me;
    me=this_player();
	me->start_busy(60);
	me->set_temp("fangcun/qiansi_gongxi",1);
	message_vision(HIY"\n\n\n不多时顿觉四周云雾缭绕,眼前金光大盛.$N不由得睁开了眼睛.\n\n"NOR,me);
	message_vision(HIY"\n只见满屋子云雾弥漫,竟有八条巨龙隐隐盘旋于云雾间.\n\n"NOR,me);
	message("chat",HIC+"\n\n〖"+HIW+"幻想西天"+HIC+"〗千里眼(Qianli yan)：方寸山三星洞前有股灵气冲天而起,莫非又是那只猴子．．．．．．\n\n\n"NOR,users());
  	call_out("finish_qiansi6",3);
    
}

void finish_qiansi2()
{
	object me;
    me=this_player();
	me->set("fangcun/panlong_noway",1);
	message("chat",HIC+"\n\n〖"+HIY+"幻想西天"+HIC+"〗菩提祖师「唉」的一声叹了口气。\n\n\n"NOR,users());
    message("chat",HIC+"〖"+HIW+"幻想西天"+HIC+"〗菩提祖师(Master puti)：我徒儿"+me->query("name")+"缘分未及，终不能解千均棒法之神韵，可惜．．．可惜！\n\n"NOR,users());
    call_out("finish_qiansi3",3);
}

void finish_qiansi3()
{
	object me;
    me=this_player();
	message_vision("\n\n菩提祖师(Master puti)：事到如今为师也只有送你点东西,以了你苦心潜思之愿了\n\n"NOR,me);
  	message_vision(HIY"\n随着菩提袍袖一摆,$N只觉得臂力大增,对千均棒法的认识又进了一步.\n\n"NOR,me);
    me->add("str",2);
    call_out("finish_qiansi4",2);
}

void finish_qiansi4()
{
	object me;
    me=this_player();
	message_vision(HIW"\n菩提祖师摇了摇头,便飘然而去了.\n\n"NOR,me);
}

void finish_qiansi6()
{
   object me,wan,dao1;
   me=this_player();
   wan=new("/d/lingtai/npc/wanfeng");
   dao1=new("/d/lingtai/npc/xiao");
  dao1->move(environment(me));
  message_vision("\n\n晚风和一个小道士听到动静跑了进来!\n"NOR,me);
   wan->move(environment(me));
   call_out("finish_qiansi7",3);
}

void finish_qiansi7()
{
   object me,guang1,dao;
   me=this_player();
   guang1=new("/d/lingtai/npc/guangxi");
   dao=new("/d/lingtai/npc/xiaodao");
  dao->move(environment(me)); 
message_vision("\n广羲子快步走了进来！\n\n"NOR,me);
   guang1->move(environment(me));
   call_out("finish_qiansi8",5);
message_vision("\n随着广羲子的后面还跟来了扫地的小童！\n"NOR,me);
}

void finish_qiansi8()
{
   object me,bo;
   me=this_player();
   bo=new("/d/lingtai/npc/shixong");
   message_vision("\n墙角一个人影闪过,原来是皤不分用移行换位看热闹来啦！\n"NOR,me);
    bo->move(environment(me));
   call_out("finish_qiansi9",3);
}
void finish_qiansi9()
{
   object me,hui1,hui2;
   me=this_player();
   hui1=new("/d/lingtai/npc/huigang");
   hui2=new("/d/lingtai/npc/huiliu");
   message_vision("\n不一会,慧琉,慧纲 两位道长也来到小室！\n"NOR,me);
    hui1->move(environment(me));
	hui2->move(environment(me));
   call_out("finish_qiansi10",3);
}

void finish_qiansi10()
{
   object me,yun1,yun2,yun3;
   me=this_player();
   yun1=new("/d/lingtai/npc/yunjing");
   yun2=new("/d/lingtai/npc/yunqing");
   yun3=new("/d/lingtai/npc/yunxiao");
   message_vision("\n云清,云静也相继赶来！\n"NOR,me);
   yun1->move(environment(me));
   yun2->move(environment(me));
   message_vision("\n远远的就传来云霄的赞叹声.\n"NOR,me);
   yun3->move(environment(me));
  call_out("finish_qiansi11",3);
}

void finish_qiansi11()
{
   object me,guang2,chen,zhangdaoling;
   me=this_player();
   guang2=new("/d/lingtai/npc/guangyun");
   
    chen=new("/d/lingtai/npc/yingke");
	zhangdaoling=new("/d/lingtai/npc/zhangdaoling");
   message_vision("\n广筠子大袖飘飘,足不点地的缓缓进来！\n"NOR,me);
      guang2->move(environment(me));
   message_vision("\n突然室外传来天师 张道陵的笑声.\n"NOR,me);
      zhangdaoling->move(environment(me));
   message_vision("\n小室的门口露出迎客小童晨月的小脑袋,正偷偷往这边瞧呢.\n"NOR,me);
call_out("finish_qiansi12",3);
}

void finish_qiansi12()
{
	object me,yunyang;
    me=this_player();
   yunyang=new("/d/lingtai/npc/yunyang");
   message_vision(WHT"\n角落里传来云阳真人严厉的声音:晨风,还不去山门迎客去？\n"NOR,me);
   message_vision("\n晨风吐了吐舌头一步三回头的走了.\n\n\n"NOR,me);
  yunyang->move(environment(me));
  call_out("finish_qiansi13",5);
}

void finish_qiansi13()
{
  object me;
  me=this_player();
   	message("chat",HIC+"\n\n〖"+HIY+"幻想西天"+HIC+"〗菩提祖师对"+me->query("name")+"哈哈大笑了几声。\n\n"NOR,users());

	message("chat",HIC+"〖"+HIW+"幻想西天"+HIC+"〗菩提祖师(Master puti)：乖徒儿"+me->query("name")+"这盘龙八式精要竟被你悟出，不过能不能掌握还要看你的
造化！"+me->query("name")+",来,来,来,我有些话要对你说．\n\n\n"NOR,users());
     message_vision(HIW"\n众人起身朝天遥拜菩提.\n\n\n"NOR,me);
     me->delete_temp("fangcun/qiansi_gongxi");
	 me->start_busy(1);
}




