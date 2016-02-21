// guangong.c 关公
//tomcat
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string jiebai();
string unjiebai();

void create()
{
        set_name(HIR"关公"NOR, ({ "guan gong","guan" }) );
        set("title", HIR"武圣 "HIG"汉寿亭侯" HIW"  仁义春秋"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("long",
                "上马金，下马银，不能改其义，千里送嫂，过五关斩六将,十八般武艺样样精通的关二爷!\n");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 120);
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        set("inquiry", ([
                "结拜" : "是啊... 这里就可以结拜",
        ]) );
        set("max_kee", 1800);
        set("max_sen", 1800);
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("literate", 250);
        set_skill("archery", 250);
        set_skill("mace", 250);
        set_skill("unarmed", 300);
        set_skill("changquan", 300);
        set_skill("yanxing-steps", 250);
        set_skill("lengquan-force", 280);
        set_skill("blade", 300);
        set_skill("spear", 250);
        set_skill("axe", 250);
        set_skill("wuhu-blade", 280);
        map_skill("force", "lengquan-force");
        map_skill("unarmed", "changquan");
        map_skill("parry", "wuhu-blade");
        map_skill("dodge", "yanxing-steps");
        
        set_temp("apply/attack",200);
        set_temp("apply/defense",200);
        set_skill("dodge", 200);
        set_skill("unarmed", 300);
        create_family("将军府", 1, "蓝");
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();

        
}

void init()
{
        object ob;

        ::init();
        add_action("do_jiebai", "jiebai");
        add_action("do_unjiebai", "duanpao");
}

int do_jiebai(string arg) {
        object obj, me;
        object ob;
        int i;
        string myclass,otherclass;
        me = this_player();
        if( me->query("jiebai"))        
                        return notify_fail(
                "你已经有生死兄弟了。\n");
 
        if(!arg || !objectp(obj = present(arg, environment(me)))
                )
                return notify_fail("你想和谁撮香结义？\n");

        if( obj->query("jiebai"))
               return notify_fail(
                "你的朋友已经有生死兄弟了。\n");
                        
        if( !living(obj) )
                return notify_fail(obj->name() + 
                "已经无法和你撮香结义了。\n"); 

        if(obj==me)     return notify_fail("别开玩笑\n");
        if(!userp(obj)) return notify_fail("你只可和玩家撮香结义．\n");


//          if ( (((int)me->query("age")<17)&&
//                  ((string)me->query("gender")=="男性")) ||
//               (((int)me->query("age")<16) &&
//                 ((string)me->query("gender")=="女性")) )
//                   return notify_fail("你太小啦，等长大后懂事了再说。\n");  

        if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
        {
                message_vision(MAG "\n$N撮香对著关二爷说道：" 
                    + RANK_D->query_self(me) 
                    + me->name() + "，愿意和"
                    + RANK_D->query_respect(obj) + 
                "有福同享，有难同当，结为生死之交！\n\n"NOR, me,obj);           
                 me->set_temp(obj->query("id") + "j",1);
           tell_object(obj, MAG "如果你愿意和对方结为生死之交，请你也对" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 jiebai 指令。\n" NOR);
                write(MAG  
                        "你向对方颔首示意...\n" NOR);
                return 1;
        }
        
        me->set("jiebai",obj->query("id"));
        obj->set("jiebai",me->query("id"));
        
        message_vision(MAG " $N 和 $n ，不愿同年同月同日生，但求同年同月同日死，结为生死之交。\n" NOR,
        obj, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 结为生死之交! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unjiebai(string arg)
{
        object jiebai_card1,jiebai_card2,  me;
        object jiebai_ob;
        int i, have_jiebai;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        if (!me->query("jiebai"))
                return notify_fail("你没有拜把子。\n");
        
        target = (string) me->query("jiebai");        

         if(!objectp(jiebai_ob = present(target, environment(me)))
                 )
                return notify_fail("你的生死之交现在不在场.\n");


        if( userp(jiebai_ob) && !jiebai_ob->query_temp(me->query("id")+"d"))
                {
                message_vision(MAG "\n$N对著$n说道：" 
                        + RANK_D->query_self(me) 
                        + me->name() + "，我要与你断袍绝义!怎么样?\n\n"
                        NOR, me, jiebai_ob);           
                 me->set_temp(jiebai_ob->query("id")+"d",1);
           tell_object(jiebai_ob, MAG "如果你愿意断袍绝义，请你也"
                + "下一次 duanpao 指令。\n" NOR);
                write(MAG  
                "现在你只有等着" +jiebai_ob->query("name")+"同意啦...\n" NOR);
                return 1;
        }

        
        message_vision(MAG " $N 和 $n 从现在开始断袍绝义,互不相干!\n" NOR,
        jiebai_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始断袍绝义,互不相干!这世道。。。 \n", 
        me->name(1), jiebai_ob->name(1)));
        me->set("jiebai",0);
        jiebai_ob->set("jiebai",0);
        me->add("duanpao",1);
        jiebai_ob->add("duanpao",1);
        return 1;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}

void attempt_apprentice(object ob)
{
	ob=this_player();
  
  if (ob->query("obstacle/number") < 34) {
	command("say 这位" + RANK_D->query_respect(ob) + "你江湖阅历太浅了！\n");
	command("sigh");
	return;
	}
 if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "老夫平生最恨不忠不义之人！\n");
	command("heng");
	return;
	}
  if (ob->query("combat_exp") < 1000000)
    {
       command("sigh");
       command("say 这位" + RANK_D->query_respect(ob) + "你武功根底太差了！\n");
       return ;
     }
    command("haha");
    command("recruit " + ob->query("id") );
    return 0;
}
