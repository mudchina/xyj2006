inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("秦富", ({"qin fu", "qin", "fu", "master"}));
  set("title", "将军府管家");
  set("gender", "男性");
  set("age", 38);
  set("str", 30);
  set("int", 25);
  set_skill("spear", 60);
  set_skill("force", 75);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("yanxing-steps", 60);
  set_skill("bawang-qiang", 60);
  set_skill("lengquan-force", 75);
  set_skill("unarmed", 75);
  set_skill("changquan", 75);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 200);
  set("max_kee", 700);
  set("force", 550);
  set("max_force", 500);
  set("force_factor", 30);
  set("combat_exp", 75000);
               set("inquiry", ([
                "下山": (: expell_me :),
                "leave": (: expell_me :),
]) );

  create_family("将军府", 3, "蓝");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();


}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "将军府") {
                command("say 大家同门中人，不敢当，不敢当！\n");
                return;
        }
             command("haha");
             command("recruit " + ob->query("id"));              
                       return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "fighter");
                ob->set("title", "将军府第四代弟子");
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="将军府") {
                me->set_temp("betray_jjf", 1);
                return ("按我大唐律法，却须受罚，你可愿意(agree)?");
        }
        return ("去问问袁先生吧，或许他知道。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray_jjf")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/fighter", 1);
                    this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("lengquan-force") )
                  this_player()->delete_skill("lengquan-force");
                if( this_player()->query_skill("baguazhou") )
                  this_player()->delete_skill("baguazhou");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}

