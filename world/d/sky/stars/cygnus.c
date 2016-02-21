
//note: this is created from player data.
inherit NPC;

void create()
{
	set_name("小令狐", ({"cygnus"}));
	set("long", @LONG
风雪剑派 --- 晓天飞雨楚峰流
    风雨纷纷风中闯江湖风雨心相戚
剑
系       风雪剑派网址
风   http://128.205.200.100/~xou
雪
情
    雪原莽莽雪下忆神州雪原映丹心

LONG);
	set("title", "房日星官");
	set("gender", "女性");
	set("age", 40);
	set("class", "taoist");
	set("attitude", "friendly");
	set("per", 11);
	set("max_kee", 1136);
	set("max_gin", 200);
	set("max_sen", 1780);
	set("force", 4452);
	set("max_force", 2226);
	set("force_factor", 143);
	set("mana", 6080);
	set("max_mana", 3040);
	set("mana_factor", 153);
	set("combat_exp", 1316264);
	set("env/no_teach", 1);

	set("eff_dx", 800000);
	set("nkgain", 800);

	set_skill("blade", 6);
	set_skill("dao", 180);
	set_skill("dodge", 199);
	set_skill("force", 202);
	set_skill("hammer", 83);
	set_skill("jindouyun", 183);
	set_skill("literate", 142);
	set_skill("moondance", 3);
	set_skill("parry", 142);
	set_skill("puti-zhi", 99);
	set_skill("qianjun-bang", 250);
	set_skill("spells", 142);
	set_skill("stealing", 12);
	set_skill("stick", 201);
	set_skill("throwing", 2);
	set_skill("tonsillit", 25);
	set_skill("unarmed", 141);
  	set_skill("whip", 48);
	set_skill("wuxiangforce", 180);
	set_skill("yaofa", 3);

	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "moondance");

	create_family("方寸山三星洞", 2, "弟子");
	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/weapon/stick/bintiegun")->wield();
}


