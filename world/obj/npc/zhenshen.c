// jia-shen.c 假身
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("真身",({"zhen shen"}));
	set("gender","男性");
	set("age",30);
	set("str",30);
	set("per",20);
	set("combat_exp",1000);
	set("daoxing",1000);
        set("attitude", "friendly");
	set_skill("dodge",10);
	set_skill("moshenbu",10);
	map_skill("dodge","moshenbu");

	setup();
}

void copy_status(object me,object ob)
{
//	object *inv;
	mapping skill_status,map_status;
	string *sname,*mname;
	int i;
	me->set("id", ob->query("id")+"'s zhenshen");
	me->set("name",ob->query("name"));
	me->set("title",ob->query("title"));
	me->set("nickname",ob->query("nickname"));

	skill_status=me->query_skills();
	sname=keys(skill_status);
	for(i=0;i<sizeof(skill_status);i++) {
		me->delete_skill(sname[i]);
	}
	skill_status=ob->query_skills();
	sname=keys(skill_status);
	for(i=0;i<sizeof(skill_status);i++) {
		me->set_skill(sname[i],skill_status[sname[i]]);
	}
	if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i]);
                }
        }

        map_status = ob->query_skill_map();
        mname  = keys(map_status);

        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
/*
	inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
                        inv[i]->unequip();
                        me->set("weapon", 0);
                }
                if( inv[i]->query("armor_prop") && inv[i]->query("equipped") ) {
                        inv[i]->unequip();
                        me->set("armor", 0);
                }
        }

	inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("weapon_prop") 
                &&  inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wield();
                        me->set("weapon", base_name(inv[i]));
                }
                else if( inv[i]->query("armor_prop") 
                &&  inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        me->set("armor", base_name(inv[i]));
                }
        }
*/
	me->set("str",ob->query("str"));
	me->set("int",ob->query("int"));
	me->set("con",ob->query("con"));
	me->set("per",ob->query("per"));
	me->set("cor",ob->query("cor"));
	me->set("spi",ob->query("spi"));
	me->set("cps",ob->query("cps"));
	me->set("kar",ob->query("kar"));

	me->set("max_kee",ob->query("max_kee"));
	me->set("eff_kee",ob->query("eff_kee"));
	me->set("kee",ob->query("kee"));

	me->set("max_gin",ob->query("max_gin"));
	me->set("eff_gin",ob->query("eff_gin"));
	me->set("gin",ob->query("gin"));

	me->set("max_sen",ob->query("max_sen"));
	me->set("eff_sen",ob->query("eff_sen"));
	me->set("sen",ob->query("sen"));

	me->set("max_force",ob->query("max_force"));
	me->set("force",ob->query("force"));
	me->set("force_factor",ob->query("force_factor"));

	me->set("max_mana",ob->query("max_mana"));
	me->set("mana",ob->query("mana"));
	me->set("mana_factor",ob->query("mana_factor"));

	me->set("combat_exp",ob->query("combat_exp"));
	me->set("daoxing",ob->query("daoxing"));
}

void die()
{
	string owner;
	object owner_ob;
	owner = query("owner");
	if( objectp(owner_ob = find_player(owner)) ) {
                        tell_object(owner_ob, "你的真身被人杀死了，你觉得一阵天旋地转....\n");
			owner_ob->move("/obj/void");
			owner_ob->unconcious(); 
	}
       message("vision",HIB + name() + "身子一晃，变成一股青烟散去了。\n" NOR,environment(),this_object() );
        destruct(this_object());
}

int heal_up()
{	object owner_ob;
	object me=this_object();
        if( objectp(owner_ob=query("owner_ob")) 
		&&  owner_ob->query_temp("in_hell") ) {
		::heal_up();
		return 1;
	}
        call_out("leave", 1);
        return ::heal_up();
}

void leave()
{
      if(this_object()) { //mon 11/23/97
        message("vision",HIB + name() + "身子一晃，变成一股青烟散去了。\n" NOR,environment(),this_object() );
        destruct(this_object());
      }
      return;
}

void invocation(object who)
{	object me=this_object();
	copy_status(me,who);
	set("owner", who->query("id"));
	set("owner_ob", who);
}

