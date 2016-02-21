//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

#define SYNTAX "指令格式：tellme [player_id] make <id>\n"

int check_ratio(object me, object ob);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);

/************************************************************/

void create()
{
  set_name("怪老道", ({"guai laodao", "laodao","daoshi"}));
  set("long",
"他是剑圣的舅舅，想当年他名震江湖，外号“八百里”，只要他出手，\n"
"方圆八百里内，没有生物能生存，现在由于年纪大了，威猛不比当年。\n"
"但剑圣仍让他看守化妖炉，因为他和剑圣一样对妖魔，绝不手下留情 。\n");
  set("title", HIY"祭师"NOR);
  set("gender", "男性");
  set("per", 10);
  set("age", 100);
  set("str", 30);
  set("int", 30);
    set("max_sen", 2000);
  set("max_kee", 2000);
    set("force", 3000);
  set("max_force", 2000);
      set("mana", 3000);
  set("max_mana", 2000);
  
        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 140);
        set_skill("sword", 130);
        set_skill("zixia-shengong", 130);
        set_skill("sevensteps",160);
        set_skill("literate", 80);
        set_skill("shushan-jianfa",130);
        set_skill("taoism",120);
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "sevensteps");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
  
   set("attitude", "peaceful");
  set("combat_exp", 1500000);
  set("daoxing",2000000);
  set("inquiry", ([
     "name": "什么名字！我自己都不记得了！",
     "here": "这里是镇妖炉，你看不出来吗？",
     ]));
  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();       
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

void init()
{
    add_action("do_put", "putin");
}

/************************************************************/

int do_put(string arg)
{
  object me=this_player(),ob;
  int neidanexp, pot, make_delay;
  int myscore, ratio, base_reward, reward, pot_reward;
  object makedan=this_object(), neidan;

          //if (userp(ob))
          //return notify_fail("这里化不了玩家的。\n");
  if (!arg) return notify_fail("你要炼谁？\n");
  if(me->is_busy()) return notify_fail("你正忙着呢。\n");
  if(is_busy()) return notify_fail("对方正忙着呢。\n");
  if(query_temp("processing"))
    return notify_fail(CYN"怪老道怒道：没看我正忙着炼内丹嘛！？\n"NOR);
  if(environment(makedan)!=find_object("/d/shushan/jisiting.c"))
    return notify_fail(CYN"怪老道摇了摇头。\n"NOR);
  if (me->query("family/family_name") != "蜀山剑派")
      return notify_fail(CYN"怪老道仔细打量了你几眼，道：奇怪，蜀山我哪个不认识，怎么就没见过你？\n" NOR);
  ob=present(arg, me);
  if (!ob || !objectp(ob))
      return notify_fail("你没有这样 "+arg+"。\n");
  if (!ob->is_character())
      return notify_fail(CYN "怪老道摇了摇头，这个是妖怪吗！\n" NOR);
  if (me->query("shushan/put_allowed")> time())
      return notify_fail(CYN"怪老道怒道：你怎么刚去就又来了！？\n"NOR);
  if (ob->query("race") == "人类" || ob->query("race") == "神仙")
      return notify_fail(CYN"怪老道骂道：浑帐！什么是妖怪你都不懂啊！？\n"NOR);
  if (ob->query("family/family_name") == "蜀山剑派")
      return notify_fail(CYN"怪老道骂道：浑帐！自己同门你都说是妖怪啊！？\n"NOR);

  if (ob->query_temp("last_fainted_from")!=me->query("id"))
      return notify_fail(HIR"怪老道一脸精明地说：不要以为我老就好骗？！\n"NOR);
  message_vision("$N将晕倒了的$n交给怪老道。\n", me, ob);
  message_vision(HIC "$N狂喜：太好了，又收服了一个妖怪！\n"NOR, makedan);
  ratio=check_ratio(me, ob);
  base_reward=check_base_reward(ob, ratio);
  reward = base_reward * ratio/100+1;
  
  CHANNEL_D->do_channel(this_object(), "rumor",me->query("name")+"又收服一妖魔，把"+ob->query("name")+"收进化妖炉！");
  
        me->set("shushan/last_put", ob->query("id"));
        me->add("shushan/put_count", 1);
        me->set("shushan/put_allowed", time()+ 150 +random(150));
        me->add("shushan/reward",reward);
    write(reward);
    message_vision("$N迅速地打开化妖炉，将$n扔了进去。\n",makedan,ob);
    message_vision("只听见哗啦哗啦的声音，$N已经被化了。\n",ob);
    me->add("family/loyalty",1);
    tell_object(me,GRN"老道告诉你：我会替你在掌门人面前说好话的！\n"+HIW"你的师门忠诚度又提升了！\n"NOR);
    destruct(ob);
  return 1;
}

int check_ratio(object me, object ob)
{
    int ratio;
    int myexp, neidanexp;

    neidanexp=ob->query("combat_exp")/3;   // neidanexp 是被卖者的强度。
    //mon changed factor to 3 from 2. 11/24/97, 12/13/97
    myexp=me->query("combat_exp");   // myexp 是卖者的强度。

    if (myexp==0) myexp=1;
    ratio=neidanexp*100/myexp;     // ratio 是被卖者除卖着的百分比。
    if (ratio>150) ratio = 150;     // 如果百分比太高（>2），则当作幸运处理。设回100%
    else if (ratio < 100)
      ratio = ratio * ratio / 100;   // 如果太低，平方，防止高手杀太低的NPC、玩家。
    return ratio;
}
int check_base_reward(object neidan, int ratio)
{
    int neidanexp=neidan->query("combat_exp"), base_reward;
    int adjust=ratio/10;

    if (neidanexp > 2000000)
   base_reward=600; 
    else if(neidanexp>1000000)
        base_reward=500;
    else if(neidanexp>500000)
        base_reward=400;
    else if(neidanexp>200000)
        base_reward=300;
    else if(neidanexp>100000)
        base_reward=250;
    else if(neidanexp>50000)
        base_reward=200;
    else if(neidanexp>10000)
        base_reward=150;
    else if(neidanexp>1000)
        base_reward=80;
    else base_reward=50;

    if (userp(neidan)) base_reward *= 2;     // 若卖玩家，奖励加倍。

    return base_reward;
}

void move_ob(object ob)
{
  return;
}

void destroy(object ob)
{
  destruct(ob);
  return;
}


