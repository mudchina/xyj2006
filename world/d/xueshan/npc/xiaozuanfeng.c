//xiaozuanfeng.c

int ask_name(); 

inherit F_VENDOR_SALE;
// inherit NPC;
void create()
{
        object yaopai;

	set_name("小钻风", ({"xiao zuanfeng", "xiao yao", "xiaoyao", "yao"}));
	set("gender", "男性" );
	set("age", 16);
        set("title", "大雪山巡山小妖");
	set("long", "去雪山路上的一个小妖，手里拿着铜锣正边走边吆喝。\n");
	set("class", "yaomo");
	set("combat_exp", 5000);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 10);

	set("per", 11);
	set("max_kee", 150);

        set("vendor_goods", ([
                "yinzhen": "/d/obj/weapon/throwing/yinzhen",
                "jiudou": "/d/xueshan/obj/jiudou",
                "peijian": "/d/obj/weapon/sword/peijian",
                "kongqueling": "/d/obj/weapon/throwing/kongqueling",
        ]) );


	setup();
	carry_object("/d/obj/armor/shoupi")->wear();

        yaopai=carry_object("/d/xueshan/obj/yaopai");
        yaopai->move(this_object());
        yaopai->set("long","\n  
              ＊＊＊＊＊＊＊＊＊＊
              ＊　　威镇群魔　　＊
              ＊＊＊＊＊＊＊＊＊＊

　              大雪山巡山使者－小钻风\n");

       set("inquiry", ([
                "name"     : (:ask_name:),
                "here"     : "这都不知道？再走两步，就是我们大雪山啦！",
                "雪山"     : "大雪山就是我家，我们三位大王正在招兵买马，要不要去看看？",
                "大大王"     : "我家大大王神通广大，本事高强，曾一口吞了十万天兵。",
                "二大王"     : "我家二大王身高三丈，卧蚕眉，丹凤眼，"
                          +"美人声，扁担牙，鼻似蛟龙。若与人争斗，"
                          +"只消一鼻子卷去，就是铁臂铜身，也就魂亡魄丧。",
                "三大王"     : "我家三大王非凡间之物，名号云程万里鹏，又叫大鹏名王，"
                          +"行动时，疾风掠海，振北图南。",
         ]) );

        set("chat_msg", ({
            "小钻风敲着铜锣吆喝道：巡山的，放哨的注意了！这几天唐僧就要从这过，大家都留点神！\n",
            "小钻风喊道：唐僧的大徒弟孙悟空尖嘴猴腮，象个雷公！\n",
            "小钻风喊道：唐僧的二徒弟猪八戒肥头大耳，象个猪骡！\n",
            "小钻风喊道：唐僧的三徒弟沙和尚满脸秽气，象个鲶鱼精！\n",
            (: random_move :),
            (: random_move :),
            (: random_move :),
        }) );
        set("chat_chance", 25);
}

void init()
{
   add_action("do_vendor_list", "list");
}


int ask_name() {
  this_object()->command("shutup xiao zuanfeng");  
  return 1;
}

