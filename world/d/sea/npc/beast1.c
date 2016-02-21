inherit NPC;
string *first_name = ({ "»¨Æ¤", "ÂÌ±³", "Ë«Í·", "»¢³İ"});
string *name_words = ({ "¹ê"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "gui" }) );
        set("race", "Ò°ÊŞ");
        set("age", 20);
        set("long", "Ò»Ö»×ãÓĞ¹ø¸Ç´óĞ¡µÄ¹Ö¹ê¡£\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 900);
        set("max_sen", 900);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "¹ê¿Ç", "Î²°Í", "¶ÇÆ¤"}) );
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 50000+random(50000));
  set("daoxing", 100000);

	set_skill("dodge", 60);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 80);
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
                return notify_fail("ÕâÖ»º£ÊŞÕıÔÚÕ½¶·¡£\n");
        if((string)who->query("family/family_name")!="¶«º£Áú¹¬")
                return notify_fail("Ê²Ã´£¿\n");
        message_vision("$N¶Ô$n´óº°Ò»Éù£ºÄõĞó£¬¿´Äã²ş¿ñµ½¼¸Ê±£¡\n\n", who,me);
        message_vision("$NÆËÉÏÀ´ºÍ$nÅ¤´òµ½Ò»Æğ¡£\n",me,who);
        me->kill_ob(who);
        who->kill_ob(me);
//        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

	if(!owner) return ::die(); // added by mon.

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("dragonforce_practice", owner_ob->query("spi")*2);
		message_vision("$NµÍÍ·ËõÎ²£¬ÒÔÊ¾½µ·ş¡£\n",this_object());
		destruct(this_object());
		return;
        }
        ::die();
}

ÿº