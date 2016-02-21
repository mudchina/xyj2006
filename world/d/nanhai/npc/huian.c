
// guanyin.c 惠岸行者
// By Dream Dec. 20, 1996
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "place.h"

string ask_for_partner();
string ask_mieyao();
string ask_cancel();

void create()
{
        set_name("惠岸行者", ({ "huian xingzhe", "huian", "xingzhe" }));
        set("title", "观音首徒");   
        set("long", @LONG
李天王二太子木叉，南海观音大徒弟惠岸行者。
LONG);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("class", "bonze");
    
    set("max_kee", 1000);
        set("max_gin", 600);
           set("max_sen", 1000);
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 75);
        set("max_mana", 1000);
        set("mana", 2000);
        set("mana_factor", 55);
        set("combat_exp", 750000);

        set("eff_dx", 150000);
        set("nkgain", 300);

        set_skill("literate", 100);
        set_skill("spells", 120);
        set_skill("buddhism", 120);
        set_skill("unarmed", 100);
        set_skill("jienan-zhi", 100);
        set_skill("dodge", 100);
        set_skill("lotusmove", 100);
        set_skill("parry", 100);
        set_skill("force", 100);
        set_skill("lotusforce", 100);
        set_skill("staff", 110);
        set_skill("lunhui-zhang", 110);
        set_skill("spear", 80);
        set_skill("huoyun-qiang", 60);
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        map_skill("spear", "huoyun-qiang");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "jingang" :)
        }) );

        set("inquiry", ([
                "dadang" : (: ask_for_partner :),
                "partner" : (: ask_for_partner :),
                "搭档": (: ask_for_partner :),
           "cancel": (: ask_cancel :),
//       "降妖": (: ask_mieyao :),
                ]) );

        create_family("南海普陀山", 2, "弟子");

        setup();
        carry_object("/obj/money/gold");
        carry_object("/d/nanhai/obj/sengpao")->wear();
        carry_object("/d/nanhai/obj/budd_staff")->wield();
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say " + RANK_D->query_respect(ob) + "未入佛门，恕贫僧不能接纳。\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 50 )) {
                command("say " + RANK_D->query_respect(ob) + "若欲深修，需得熟读佛法。\n");
                return;
        }
        command("nod");
        command("say 很好，贫僧就收下你，希望你多加努力，早成正果。\n");

        command("recruit " + ob->query("id") );
        message("system", HIR"惠岸行者："HIY"南海普陀山又多了一个弟子  "+this_player()->name()+HIW"

                            南海普陀山的势力加强了。\n"NOR,users());     
        return; 
}

string ask_for_partner()
{

        object me = this_player();
        string dadang;

        if ( (string)me->query("family/family_name")!="南海普陀山")
                return "只有南海普陀山弟子才能寻找搭档。\n";
        if( (string)me->query("bonze/class")!="bonze" )
                return "施主既非佛门中人，何必多问？\n";
        if( (dadang=(string)me->query("bonze/dadang")) !=0 )
                return "你的搭档是"+dadang+"。\n";

        me -> set_temp("pending/dadang_inquiry", 1);

        return RANK_D->query_respect(me)+"请用 \"dadang <id>\" 来选择你的搭档。\n";
}

int do_dadang(string arg)
{
object obj, me=this_player();
string dadang;

        if ( (string)me->query("family/family_name")!="南海普陀山")
                return notify_fail("只有南海普陀山弟子才能寻找搭档。\n");
        if( (string)me->query("bonze/class")!="bonze" )
                return notify_fail("施主既非佛门中人，何必多问？\n");
        if( (dadang=(string)me->query("bonze/dadang")) !=0 )
                return notify_fail("你的搭档是"+dadang+"。\n");
        if( !me->query_temp("pending/dadang_inquiry") ) 
                return notify_fail("你还没问过"+this_object()->query("name")+"呢！\n");
        me->delete("pending/dadang_inquiry");

        if (!arg) 
                return notify_fail("你要和谁做搭档？\n");

        obj = present(arg, environment(me));
        if (!userp(obj)) return notify_fail("\n");

//        if (me->query("gender") == obj->query("gender") )
//                return notify_fail("你只能与异性同门做搭档。\n");

        if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        if( obj->query_temp("pending/dadang") != me) {
                message_vision("\n$N当着"+this_object()->query("name")+"的面，对$n说道："
                        + RANK_D->query_self(me)+ me->name() 
                        + "，欲与" + RANK_D->query_respect(obj)
                        + "做一对搭档，日后一起行走江湖，同生死，共患难，"
                        + RANK_D->query_respect(obj) + "意下如何？\n\n", me, obj);
                me->set_temp("pending/dadang", obj);
                return 1;
        }

        obj->delete_temp("pending/jiebai");
        message_vision("\n$N当着"+this_object()->query("name")+"的面，对$n说道："
                + RANK_D->query_self(me)+ me->name() 
                + "，愿与" + RANK_D->query_respect(obj)
                + "做一对搭档！\n\n", me, obj);

        obj->set("bonze/dadang", me->query("name"));
        obj->set("bonze/dadangid", me->query("id"));
        me->set("bonze/dadang", obj->query("name"));
        me->set("bonze/dadangid", obj->query("id"));
        return 1;


}

void init()
{
        add_action("do_dadang", "dadang");
        add_action("do_kneel", "kneel");
}

string ask_mieyao()
{
    object who=this_player();
        
    if((string)who->query("family/family_name")=="南海普陀山") {
      command("say 灭妖除魔，乃我佛门中人之本分。");
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}

int do_kneel()
{
    object who = this_player();
    
    if((string)who->query("family/family_name")!="南海普陀山")
     return notify_fail(this_object()->query("name")+"说：你又不是普陀弟子，拜我干什么？\n");
    if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say 既然如此，就算了吧，不过你没有完成任务，得受些惩罚！\n");
        who->add("faith",-5);
        message_vision("$N的忠诚度下降了！\n",who);
     }
     return 1;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}


