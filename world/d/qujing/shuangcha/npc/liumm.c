//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// jiading.c

inherit NPC;

void create()
{
       set_name("刘母", ({"liu mama","mama"}));
       set("long","一个慈祥的老太太．\n");
       set("gender", "女性");
       set("age", 66);
       set("str",40);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1800);
       set_skill("stick", 15);
       set_skill("parry", 25);
       set_skill("dodge", 35);
       set("force_factor", 3);
        set("chat_chance",50);
        set("chat_msg", ({
        "刘母叹息道：儿呀，你该去找个会念经的和尚为你父亲超度啊。\n",
        "刘母喃喃的念道：“南无阿弥陀佛”\n",
        }));
        setup();
        add_money("coin", 50);
 	carry_object("/d/qujing/shuangcha/obj/cloth")->wear();
 	carry_object("/d/qujing/shuangcha/obj/fozhu")->wear();

}

