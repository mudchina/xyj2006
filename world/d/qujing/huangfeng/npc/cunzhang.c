// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/cunzhang

inherit NPC;
void create()
{
       set_name("老村长", ({"cun zhang", "wang"}));

set("long","王家村村长，看起来精明能干。\n");
       set("gender", "男性");
       set("age", 61);
       set("per", 100);
	set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 5000);
       set_skill("unarmed", 15);
	set_skill("dodge", 30);
	set_skill("parry", 15);
set("inquiry", ([
"name": "在下姓王，乃是本村的村长．\n",
"here": "王家村是也．\n",
"rumors": "近来黄风岭上妖怪越来越凶，早晚有一日会欺到村里来，真不知如何是好！\n",
"黄风岭": "此去三十里远近，有一座山，叫做八百里黄风岭。那山中多有妖怪。\n",
"妖怪": "闻说那些怪厉害得紧，见过的人没一个活着回来的，老汉我也只是听说，不曾见过。\n",
]) );

	setup();
       add_money("silver", 30+random(5));
	carry_object("/d/ourhome/obj/choupao")->wear();
}
