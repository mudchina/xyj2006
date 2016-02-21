// leader.c

inherit NPC;

void create()
{
       set_name("吴文", ({"wu wen", "wen", "wu"}));
       set("long","一个看起来颇有风度的中年人，背着手闲逛．\n");
       set("gender", "男性");
	set("title", "村长");
       set("age", 46);
	set("combat_exp", 8000);
	set_skill("unarmed", 15);
	set_skill("dodge", 15);
	set_skill("parry", 15);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("chat_chance", 10);
set("inquiry", ([

"name"  : "老夫姓吴，单名一个文字．",
"here"  : "这儿哪您还不清楚吗？嘿嘿．．．",

]));
        set("chat_msg", ({
            "村长上上下下打量了你几眼。\n",
            (: random_move :)
        }) );

	setup();
	add_money("silver", 2);
        carry_object("/obj/cloth")->wear();

}


int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
 if((string)ob->query("name")=="竹制物什" )
        {
         command("smile");
         command("say 这位" + RANK_D->query_respect(me) +"真是有心人，我就赠一礼物予你。");
        call_out("destroy", 1, ob);
        lw->move(me);
        
        return 1;       
        }
 }
void destroy(object ob)
{
        destruct(ob);
        return;

}
