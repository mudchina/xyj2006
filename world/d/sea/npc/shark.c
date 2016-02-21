inherit NPC;
string *first_name = ({ "花皮", "绿背", "双头", "虎齿"});
string *name_words = ({ "鲨"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "shark" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只模样凶恶的大鲨鱼。\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("limbs", ({ "头部", "身体", "前鳍", "尾巴", "肚皮"}) );
        set("verbs", ({ "bite"}) );

        set("combat_exp", 100000+random(10000));
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);
	set_weight(500000);
        setup();
}


void init()
{
        ::init();
        add_action("do_train", "train");
}

int do_train()
{
        object me,who;
        me =this_object();
        who=this_player();

        if(me->is_fighting())
                return notify_fail("这只海兽正在战斗。\n");
        if((string)who->query("family/family_name")!="东海龙宫")
                return notify_fail("什么？\n");
        message_vision("$N对$n大喊一声：孽畜，看你猖狂到几时！\n\n", who,me);
        message_vision("$N扑上来和$n扭打到一起。\n",me,who);
        me->kill_ob(who);
        who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

	if(!owner) {
          ::die(); // added by mon.
          return;
        }

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("dragonforce_practice",
owner_ob->query("spi")*2+random(30));
		message_vision("$N低头缩尾，以示降服。\n",this_object());
		message_vision("$N灰溜溜地游走了。\n",this_object());
		destruct(this_object());
		return;
        }
        ::die();
}

