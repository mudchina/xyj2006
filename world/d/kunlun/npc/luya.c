inherit NPC;
string ask_for_leave();

void create()
{
        set_name("陆压", ({"luya"}));
        set("gender", "男性" );
        set("age", 40);
        set("title","昆仑山玉虚洞管家");
        set("long", "昆仑山玉虚洞散仙陆压，在洞中兼任管家之职。\n");
        set("combat_exp", 50000);
  set("daoxing", 500000);

        set("attitude", "peaceful");
        set("per", 35);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("inquiry", ([
                "脱离" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
                ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        }

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "昆仑山玉虚洞" ) {
                command("say 你既是执意下山，本仙却有几句话说。");
                me->set_temp("betray", 1);
                return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
        }

        return ("本仙不知。\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                command("say 既是你执意下山，你便下山去吧！");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/kunlun", 1);
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
                if( this_player()->query_skill("yuxu-spells") )
                    this_player()->delete_skill("yuxu-spells");
                if( this_player()->query_skill("xuanzong-force") )
                    this_player()->delete_skill("xuanzong-force");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say 反复无长，自会吃亏，好自为之。。。\n");
                return 1;
        }
}
