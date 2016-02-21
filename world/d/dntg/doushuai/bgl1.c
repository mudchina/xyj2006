//created by vikee
//2000.10

#include <ansi.h>
inherit ROOM;

void ready_tongming(object ob);

void create()
{
   set("short", "八卦炉　乾宫");
   set("long",@LONG

这八卦炉中四处都是文武之火，坐在其中，只感到浑身燥热难当。

LONG
        );
 
   set("exits", ([
        "east" : __DIR__"bgl2",
        "north" : __DIR__"bgl4",
                "west": __DIR__"bgl6",
                "south": __DIR__"bgl8",
   ]));
   set("valid_startroom", 1);
   set("objects",([
      "/d/dntg/sky/npc/huobing" : 1,      
   ]));
   setup();
}

void init()
{
   object me = this_player();

   if(!me->query("huoyan/time")) return;
   if(me->query_temp("huoyan/calling")) return;
   me->set_temp("huoyan/calling",1);
   call_out("do_check",20,me,this_object());
}

void do_check(object ob, object env)
{
   object guai,me = ob;

   string *msg = ({
      HIY"四壁卷起一团火焰，烧得你焦头烂额！\n"NOR,     
   });
   string *huo = ({
      "/d/dntg/sky/npc/huolong.c",
      "/d/dntg/sky/npc/huoma.c",
      "/d/dntg/sky/npc/huoya.c",
      "/d/dntg/sky/npc/huoshu.c",
   });

   remove_call_out("do_check");
   
   if(!userp(ob)) return;
   tell_object(ob,msg[random(sizeof(msg))]);
   
   if(env != environment(ob) && !ob->is_fighting()
      && living(ob) && random(2) ){
      guai= new(huo[random(sizeof(huo))]);
      guai->move(environment(ob));
          message_vision("只见火部神兵，将手中的令旗一展，顿时四壁熊熊大火向你卷来！\n");
      message_vision("熊熊烈火中突然窜出一只$N。\n",guai);
   }
   
   if((int)me->query("huoyan/time") > 20) me->add("huoyan/time",-20);
   else {
      me->set("huoyan/bgl","done");
      me->set("startroom","/d/city/kezhan");
      me->save();
      tell_room(environment(ob),"炉外老君说：七七四十九天已过，谅那厮也早已被炼成灰烬！\n");
      tell_room(environment(ob),"老君高叫一声：童儿，开炉！\n");
      message_vision("炉门打开了，$N“蹦”的跳了出去！\n",ob);
      ob->move("/d/dntg/sky/tongmingdian");
      tell_room(environment(ob),"众天丁抬来一做炼丹炉，“呼”的一声从里面蹦出一个人来。\n",ob);
      ready_tongming(ob);
      return;
   }
   me->add("kee",-100);
   call_out("do_check",20,ob,environment(ob));
}

void ready_tongming(object ob)
{
   object guan,*list,laojun;
   int i,n;
   int ysn = 0, lgn = 0;  
   mixed env = find_object("/d/dntg/sky/tongmingdian");

   if(!env) env = "/d/dntg/sky/tongmingdian.c";
   laojun = new(__DIR__"npc/tslj");    
   laojun->command_function("chat 大事不好！"+ob->name()+"从八卦炉中逃出来了！\n");
   message_vision(""HIR"$N怒火上撞，一脚踢翻老君炉，断喝一声：待我杀到天庭，夺了那昏君的宝座！"NOR"\n",ob);
   destruct(laojun);
   list = all_inventory(env);
   i = sizeof(env);
   while(i--){
      if(list[i]->query("id")=="ling guan" && !userp(list[i])) lgn +=1;
   }
   if( !guan = present("yousheng zhenjun",env)){
      guan = new("/d/dntg/sky/npc/yszj.c");
      guan->move(env);
   }
   guan->command_function("chat "+ob->name()+"这个"+RANK_D->query_rude(ob)+"打到通明殿了！\n");
   message_vision("$N挥手一招，唤来几名灵官，将$n围在中间！\n",guan,ob);
   if(ysn != 4)
      for(n==0;n< 4-lgn;n++){
         guan = new("/d/dntg/sky/npc/lingguan");
         guan->move(env);
      }
   return;
}



