// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;
string ask_sanshou();

void create()
{
       set_name("痴梦仙姑",({"chi meng","dream", "fairy"}));
       set("long",
"此乃迷津痴梦仙姑也；不受金银之谢，但遇有缘者渡之！\n");
       set("title", "迷津渡者");
       set("gender", "女性");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 1000000);

        set("eff_dx", 100000);
        set("nkgain", 300);

       set_skill("literate", 90);
       set_skill("parry", 100);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 120);
       set_skill("whip", 180);
       set_skill("unarmed", 80);
       set_skill("spells", 120);
       set_skill("baihua-zhang", 120);
        set_skill("moonshentong",140);
        set_skill("jueqingbian", 180);
        set_skill("moonforce", 120);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("whip", "jueqingbian");
        map_skill("parry", "jueqingbian");
        map_skill("dodge", "moondance");
        set("inquiry",([
      "三无三不手": (: ask_sanshou :),
      ]));


create_family("月宫", 2, "弟子");
setup();

       // carry_object("/d/obj/book/lovebook");
        carry_object("/d/obj/cloth/luoyi")->wear();
   carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}
string ask_sanshou()
{
    object me=this_player();

    if(me->query("family/family_name") != "月宫" )
                return ("你不是我月宫弟子!!\n");
    if(me->query("faith")<500)
       return ("你对本门做了多少贡献，就想打听三无三不手！");
    if( (string)me->query("gender") !="女性")
                return ("你非为纯阴之身,怎能知哓女儿家的心思??\n");
    if(me->query("family/master_id") != "chi meng")
     return ("你不是我的弟子,不传。\n");
    if(me->query("JQB_known"))
      return ("你不是已经知道了么，难道是来戏弄我的！");
    command("pat "+me->query("id"));
    me->set("JQB_known",1);
    return ("你附耳过来，三无三不手乃如此如此...");
}
void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
   RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return ;
        }
   if (random(this_player()->query_kar()) < 20 || this_player()->query("mark/moon_chimeng")){
     this_player()->set("mark/moon_chimeng", 1);
     command("shake");
     command("say 你我无缘，还是另请高就吧。\n");
     return ;
   }
        else{
   command("pat "+ob->query("id"));
        command("say 既然" + RANK_D->query_respect(ob) +
"与我有缘，我就收下你了。\n");
        command("recruit " + ob->query("id") );
        return ;}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}

