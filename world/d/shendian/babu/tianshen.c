
#include <ansi.h>

inherit NPC;
string ask_tianshen();
string ask_tianshentai();

void create()
{
  set_name(HIR"帝释"NOR, ({ "tian shen", "di shi" ,"fo" }));
  set("title", HIB"八部天龙"NOR);
  set("long", "众天神的领袖。\n");
  set("gender", "男性");
  set("age", 10000);
  set("attitude", "peaceful");
  set("str",100);
  set("per",100);
    set("max_kee", 6000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 5000);
  set("max_force", 5000);
  set("force_factor", 200);
  set("max_mana", 5000);
  set("mana", 5000);
  set("mana_factor", 200);
    set("combat_exp", 3500000);
    set("daoxing", 6500000);
  set_skill("literate", 300);
   set_skill("spells", 300);
   set_skill("buddhism", 300);
  set_skill("unarmed", 220);
  set_skill("jienan-zhi", 220);
  set_skill("dodge", 220);
  set_skill("lotusmove", 220);
  set_skill("parry", 220);
  set_skill("force", 220);
  set_skill("lotusforce", 220);
  set_skill("staff", 220);
  set_skill("lunhui-zhang", 220);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                "tianshentai" : (: ask_tianshentai :),
                "天神台" : (: ask_tianshentai :),
                ]) );
  set("chat_chance_combat", 50);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
        create_family("南海普陀山", 1, "菩萨");
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}
void init()
{
        ::init();
        add_action("do_fight", "fight");
        add_action("do_cast", "cast");
        add_action("do_ji", "ji");
}
 void kill_ob (object ob)
{
  set_temp("my_killer",ob);
        ::kill_ob(ob);
}
int do_cast (string arg)
{
  object who = this_player();
   if ((arg == "qiankun") || (arg == "qiankun on tian shen") || (arg == "qiankun on di shi") || (arg == "qiankun on fo"))
  {
      tell_object(who,"少来这一套！\n");
      return 1;
     }
  else return 0;
}
int do_ji (string arg)
{
  object who = this_player();
      tell_object(who,"少来这一套！\n");
      return 1;
}
string ask_tianshen()
{
        object me = this_player();
    object jingshu;
    if(!(((string)me->query_temp("babu/qianluopo") == "done") && ((string)me->query_temp("babu/yecha") == "done") &&
 ((string)me->query_temp("babu/longshen") == "done") && ((string)me->query_temp("babu/jinnaluo") == "done") &&
 ((string)me->query_temp("babu/axiuluo") == "done") && ((string)me->query_temp("babu/jialouluo") == "done") &&
 ((string)me->query_temp("babu/mohuluojia") == "done")))
   return "其他七部同意没有？\n";
    command("nod");
    command("say 我这里有一本经书，你拿去，可以帮助你达到众神之殿。\n");
    jingshu = new("/d/shendian/babu/obj/fahua");
   jingshu->set_temp("owner",me);
    jingshu->move(me);
    me->set_temp("babu/tianshen","done");
    me->delete_temp("babu/qianluopo");
   me->delete_temp("babu/yecha");
     me->delete_temp("babu/longshen");
    me->delete_temp("babu/jinnaluo");
    me->delete_temp("babu/axiuluo");
    me->delete_temp("babu/jialouluo");
    me->delete_temp("babu/mohuluojia");
    return "祝你早日成功。\n";
}
 string ask_tianshentai()
{
   object me = this_player();
    if(me->query("babu/shendian") == "done")
    {
    command("nod");
    me->move("/d/shendian/tianshentai");
    return "好吧，我送你一程！\n";
    }
    else
    {
    return "你去过哪里吗？\n";
    }
}
void die ()
{
  object me = this_object();
 object ob = query_temp("my_killer");
  object shelizi;
   string shelizi_given,gujian_given,dao,axe,stick,staff,whip,hammer,spear,fork,mace;
  shelizi_given = "/d/shendian/babu/obj/gujian.c";
 gujian_given = "/d/shendian/babu/obj/shelizi.c";
  dao = "/d/shendian/babu/obj/gudao.c";
  axe = "/d/shendian/babu/obj/guaxe.c";
  stick = "/d/shendian/babu/obj/gustick.c";
  whip = "/d/shendian/babu/obj/guwhip.c";
  hammer = "/d/shendian/babu/obj/guhammer.c";
  spear = "/d/shendian/babu/obj/guqiang.c";
  fork = "/d/shendian/babu/obj/gufork.c";
   staff = "/d/shendian/babu/obj/gustaff.c";
   mace =  "/d/shendian/babu/obj/gumace.c";
 if ((!shelizi_given->in_mud()) && (!gujian_given->in_mud()) && (!dao->in_mud()) && (!axe->in_mud()) && (!stick->in_mud()) && (!whip->in_mud()) && (!hammer->in_mud()) && (!spear->in_mud()) && (!fork->in_mud()) && (!staff->in_mud()) && (!mace->in_mud()))
         {
  shelizi = new("/d/shendian/babu/obj/shelizi");
   shelizi->set("no_give", 1);
  shelizi->move(ob);
message_vision ("\n$N"HIY" 大叫一声:善哉，善哉，老夫去也，金光一闪，天神化做舍利子，落在$n身上......\n\n"NOR,me,ob);
  destruct (this_object());
  return ;
       }
    else
       {
 message_vision ("$N"HIY"化做一道金光，消失了......\n"NOR,me);
 destruct (this_object());
 return ;
         }
  return ;
}
int do_fight (string arg)
{
  object who = this_player();
      tell_object(who,"这里不能fight！\n");
   return 1;
}
