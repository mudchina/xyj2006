// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/girlkid.c

inherit NPC;

void create()
{
       set_name("小女孩", ({ "kid","tong","nu tong","boy" }));
       
set("long","样子聪明可爱，正帮着大人们做饭呢！\n");
       set("gender", "女性");
       set("age", 10);
	   set("per",28);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("combat_exp", 237);
setup();
add_money("coin", 10);
}
