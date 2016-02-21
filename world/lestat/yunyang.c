
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;
inherit F_MASTER;
#include "/d/obj/lquest.h"
#include "/d/lingtai/npc/zhenfa.h"

string do_task();
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();
void re_rank(object who);

void create()
{
       set_name("云阳真人", ({"master yunyang", "master", "yunyang"}));
       set("long", "云阳真人与菩提祖师实是半师半友，也是三星洞内外总管．
因其壮年时降魔除妖无数，人称「小天师」．\n");
      set("faith",4000);
       set("gender", "男性");
   set("title", "小天师");
   set("class", "taoist");
       set("age", 70);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老道长");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2100);
       set("max_gin", 2100);
       set("max_sen", 2100);
       set("force", 6300);
       set("max_force", 3200);
       set("force_factor", 80);
       set("max_mana", 3200);
       set("mana", 6300);
       set("mana_factor", 160);
       set("combat_exp", 2800000);

        set("eff_dx", 2500000);
        set("nkgain", 400);

       set_skill("literate", 190);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("parry", 220);
   set_skill("stick", 220);
   set_skill("spells", 220);
   set_skill("dao", 220);
   set_skill("puti-zhi", 220);
   set_skill("wuxiangforce", 220);
   set_skill("force", 220);
   set_skill("qianjun-bang", 220);
   set_skill("jindouyun", 220);
   map_skill("spells", "dao");
   map_skill("unarmed", "puti-zhi");
   map_skill("force", "wuxiangforce");
   map_skill("stick", "qianjun-bang");
   map_skill("parry", "qianjun-bang");
   map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
          (: perform_action, "qiankun" :),
          (: perform_action, "leiting" :),
     (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([
    "灭妖": (: ask_mieyao :),
     "下山": (: expell_me :),
     "leave": (: expell_me :),
    "task": (: do_task :),
      "cancel": (: ask_cancel :),
     "四象阵" : (: ask_sixiang :),
     "八卦阵" : (: ask_bagua :),
]) );

create_family("道界", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/bang")->wield();
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
void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="道界") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才是。\n");
   return;
   }
        command("smile");
   command("say 好极，好极，时下妖魔当道，鬼怪横行。象"  + RANK_D->query_respect(ob) +
"这样的正义之士却是少见！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
   return;
   }
   command("shake");
   command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="道界") {
                command("say 你既是执意下山，为师却有几句话说。");
                me->set_temp("betray", 1);
     command("say 我方寸山也是名门正派，道家正宗。国有国法，山有山规！");
                return ("既是要出山，却需受山规惩罚，你可愿意(agree)?");
        }
        return ("贫道不知。");
}
void init()
{
      ::init();
      re_rank(this_player());
      add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/fangcun", 1);
                command("say 既是我方寸山池浅容不下蛟龙，你便下山去吧！");
this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
             this_player()->set("faith",0);
     this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
                }
        return 0;
}

string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="方寸山三星洞") {
//  if(me->query("faith")<100)
//      return ("你还是先多加修炼为妙。");
    tell_room(environment(me),"云阳真人举起手中的木杖，顿时一道光芒射出。\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("贫道不知。");
}

string do_task()
{
    object me=this_player();
        
    if(me->query("family/family_name")!="道界")
       return ("你不是本门弟子！");
   if(me->query("combat_exp")<1100000)
        return ("你的经验还不够！");
    if(me->query("longquest/name"))
       return ("你已有任务在身！");
       
     give_quest(me);
     return ("你这就去吧！");   
}

int do_fuming()
{
     fuming(this_player());     
     return 1;
}
void re_rank(object who)
{
    int faith=who->query("faith");
    if(who->query("class")!="taoist")return;
    if(faith<=100){
        if(who->query("gender")=="女性")
           who->set("title","道界方寸山三星洞道姑");
        else who->set("title","道界方寸山三星洞道士");
        return;
     }else if(faith<=300){
        who->set("title","道界方寸山三星洞小真人");
        return;
     }else if(faith<=600){
        who->set("title","道界方寸山三星洞真人");
        return;
    }else if(faith<=1000){
        who->set("title","道界方寸山三星洞小天师");
        return;
    }else if(faith<=1800){
        who->set("title","道界方寸山三星洞天师");
        return;
    }else if(faith<=3000){
        who->set("title","道界方寸山三星洞大天师");
        return;
    }else if(faith<=6000){
        who->set("title","道界方寸山三星洞长老");
        return;
    }else who->set("title","道界方寸山三星洞元老");
    return;
}


