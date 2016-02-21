//Cracked by Roath
 
inherit NPC;
string ask_hanshan();

void create()
{
        set_name("法明长老", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set("long",
                "法明长老是化生寺的主持，神色庄重，举止间自有一番威仪。
听说他有一身武艺，也能呼风唤雨，却不传授于寺里的和尚。\n");
   set("title", "主持");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_kee", 900);
        set("max_sen", 600);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("max_mana", 500);
        set("mana", 900);
        set("mana_factor", 30);
        set("combat_exp", 200000);
	set("daoxing",200000);	
        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


        set_skill("force", 90);
        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("jienan-zhi", 90);
        set_skill("parry", 90);
        set_skill("spells", 90);
        set_skill("buddhism", 90);
        map_skill("unarmed", "jienan-zhi");
        map_skill("spells", "buddhism");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );
        set("inquiry", ([
                "血书": (: ask_hanshan :),
                "汗衫": (: ask_hanshan :),
                ]));
        set("count",1);
        setup();
        carry_object("/d/obj/cloth/monkcloth")->wear();

}

string ask_hanshan()
{
        object ob=this_player();
        object me=this_object();
        object xueshu,hanshan;
       

        if (query("count") < 1)
                return "我这已经没有了。";
//判断是否dntg over by dragon
        if( ob->query("obstacle/jz") == "done" )
        {
        command("shake");
        return("贫僧不知。");
        }
       
        if( present("xue shu", ob) || present("han shan", ob) )
        return("你不是有吗？");

        xueshu = new("/d/jz/obj/xueshu");
        hanshan = new("/d/jz/obj/hanshan");
        switch ( random(2) ) {
        case 0:
        xueshu->move(ob);
        break;
        case 1:
        hanshan->move(ob);
        break;
        }  
      add("count",-1);
      return("这是当年从玄奘身上发现的，你拿去吧。");
}        
        
        
