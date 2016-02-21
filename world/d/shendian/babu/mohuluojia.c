inherit NPC;
#include <ansi.h>
string ask_tianshen();
 string ask_done();

void create()
{
       set_name(HIR"摩呼罗迦"NOR, ({"mohu luojia"}));
        set("long","一个大蟒神，人身而蛇头。\n");
       set("gender", "男性");
       set("age", 20);
        set("title", HIB"八部天龙"NOR);
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
        set("str", 30);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 1600);
       set("mana", 3000);
       set("mana_factor", 80);
        set_skill("huomoforce", 160);
        set_skill("pingtian-dafa", 160);
        set_skill("unarmed", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("parry", 200);
        set_skill("spells", 160);
        set_skill("fork", 200);
        set_skill("yueya-chan", 160);
        set_skill("moshenbu", 160);
        set_skill("moyun-shou", 160);
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("parry", "yueya-chan");
        map_skill("fork", "yueya-chan");
        create_family("火云洞", 2, "蓝");
        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                "done" : (: ask_done :),
                ]) );
        setup();
        carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}
string ask_tianshen()
{
        object me = this_player();
    object mixin;
   if ( (string)me->query_temp("babu/mohuluojia") == "begin")
              return "东西送到了吗？\n";
        if ( (string)me->query_temp("babu/mohuluojia") == "done")
         return "我不是已经告诉你了吗？\n";
        if ( (string)me->query_temp("mohuluojia/mixin") == "done")
      return "信已经给你了哦！\n";
  command("say 你想知道众神之殿在哪里啊？\n");
  command("hmm ");
  command("say 告诉你也可以，你先帮我把这个东西送给阿修罗。\n");
 me->set_temp("babu/mohuluojia","begin");
  mixin = new("/d/shendian/babu/obj/mixin");
  mixin->move(me);
 return "送完回来可要告诉我完成了哦！\n";
}
string ask_done()
{
     object me = this_player();
     if(me->query_temp("babu/mohuluojia") == "begin")
    {
    if(me->query_temp("mohuluojia/mixin") == "begin")
            return "东西送到了吗？\n";
  command("say 恩，干的不错！\n");
  command("say 你去找天神帝释吧！\n");
    me->set_temp("babu/mohuluojia","done");
    me->delete_temp("mohuluojia/mixin");
    return "去吧! \n";
    }
    else
    {
    return "完成什么了？\n";
    }
}
