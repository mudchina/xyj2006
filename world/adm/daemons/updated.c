// updated.c
#include <ansi.h>

void create() { seteuid(getuid()); }

void check_user(object ob, int reconnect)
{
	int v1, v2;
	string m;
	mapping my;

    mapping colors;
    string key;
    int i,j,k;

	//check if daoxing 不堕轮回 
	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) ) 
		                >= RANK_D->grade_dx(HIC "不堕轮回" NOR) )
        {
            ob->announce_live_forever(ob->query("name")+
    "的道行达到了不堕轮回的境界，从此跳出三界外，不在五行中，永无生死大限了！");    
        }
	
	//set player's life time here.
	if( !ob->query("life/init_life_time") ) 
	{
	    ob->set("life/init_life_time", 50+ob->query("kar")+random(20));
	    //average is 50+20+10=80, lowest=50+10+0=60, highest=50+30+20=100
	}
	if( !ob->query("life/life_time") )
	{
	    ob->set("life/life_time", ob->query("life/init_life_time"));
	}
	//now check if gameover...player too old?
	if( ob->check_gameover() ) return; 
	//note, if gameover, the function check_gameover() return 1.
	    
	
	// player body is a safe room. mon 8/2/98
	// can't practice, ... inside a body.
	ob->set("no_magic", 1);

	ob->delete_skill("antielem");

	ob->delete_skill("octigua-magic");
	if( (string)ob->query_skill_mapped("spells")=="octigua-magic" )
		ob->map_skill("spells");
	if( (string)ob->query_skill_mapped("magic")=="octigua-magic" )
		ob->map_skill("magic");

	if( (v1=ob->query_skill("evolution", 1)) > 0 ) {
		if( (v2=ob->query_skill("magic", 1)) > 0 ) {
			ob->set_skill("spells", v2);
			if( stringp(m=ob->query_skill_mapped("magic")) ) {
				ob->map_skill("magic");
				ob->map_skill("spells", m);
			}
		}
		ob->set_skill("magic", v1);
		ob->delete_skill("evolution");
		ob->map_skill("evolution");
	}

	if( (v1=ob->query_skill("essence", 1)) > 0 ) {
		ob->set_skill("force", v1);
		ob->delete_skill("essence");
		if( stringp(m=ob->query_skill_mapped("essence")) ) {
			ob->map_skill("essence");
			ob->map_skill("force", m);
		}
	}

	my = ob->query_entire_dbase();
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];

// added by dream to clear ppl's invisibility and immortal when updated
// for future spells. July 11, 1997.

	if ( !wizardp(ob) && ob->query("env/invisibility") )
		ob->set("env/invisibility", 0);
	if ( !wizardp(ob) && ob->query("env/immortal") )
		ob->set("env/immortal", 0);

	// by snowcat - adjust title
	if (ob->query("zhangmen"))
	{
	  object zhangmen = new (ob->query("zhangmen/base_name"));

          if (zhangmen)
	  {
	    zhangmen->set_save_file(ob->query("zhangmen/data_name"));
	    zhangmen->restore();

	    if (zhangmen->query("family/family_name")!=ob->query("family/family_name"))
	    {
	      // already betrayed
	      if (ob->query("title")==ob->query("zhangmen/title") ||
	          ob->query("title")==ob->query("zhangmen/title_old"))
	      {
	        if (ob->query("family/family_name"))
	          ob->set("title",
	                    sprintf("%s第%s代%s",
	                            ob->query("family/family_name"),
	                            chinese_number(ob->query("family/generation")),
	                            ob->query("family/title")));
	      }
	      if (zhangmen->query("current_player")==ob->query("id"))
	      {
	        zhangmen->reset_me(zhangmen);
	        zhangmen->save();
	      }
	      ob->delete("zhangmen");
	    }
	    else if (zhangmen->query("current_player")==ob->query("id"))
            {
	      ob->set("title",ob->query("zhangmen/title"));
            }
	    else
	    {
	      /*
	      ob->set("title",
	                sprintf("%s第%s代%s",
	                        ob->query("family/family_name"),
	                        chinese_number(ob->query("family/generation")),
	                        ob->query("family/title")));
	       */
	      ob->set("title",ob->query("zhangmen/title_old"));
	      ob->delete("zhangmen");
	    }
            ob->save();
	  }
	}

	// by snowcat
	// the following is used to update ob's data in case
	// of system change
	{
          int tmpint;
          string tmpstr;

	  if (tmpint = ob->query("obstacle/level"))
	  {
	    if (! ob->query("obstacle/number"))
	      ob->set("obstacle/number",tmpint);
	  }
	  if (tmpstr = ob->query("obstacle/1"))
	  {
	    if (ob->query("obstacle/nuerguo"))
	    {
	      // already there
	    }
	    else if (tmpstr == "marriage" ||
	             tmpstr == "company" ||
	             tmpstr == "stomachache")
	      ob->set("obstacle/nuerguo",tmpstr);
	    else
	      ob->set("obstacle/nuerguo","done");
	  }
	  if (tmpstr = ob->query("obstacle/2"))
	  {
	    if (ob->query("obstacle/firemount"))
	    {
	      // already there
	    }
	    else if (tmpstr != "done")
	      ob->set("obstacle/firemount",tmpstr);
	    else 
	      ob->set("obstacle/firemount","done");
	  }
	  if (tmpint = ob->query("obstacle/2_bone"))
            ob->set("obstacle/firemount_bone",tmpint);
	  if (tmpstr = ob->query("obstacle/3"))
	  {
	    if (ob->query("obstacle/wudidong"))
	    {
	      // already there
	    }
	    else
	      ob->set("obstacle/wudidong",tmpstr);
	  }
	  ob->delete("obstacle/level");
	  ob->delete("obstacle/1");
	  ob->delete("obstacle/2");
	  ob->delete("obstacle/2_bone");
	  ob->delete("obstacle/3");
	}

	// by snowcat
	if (ob->query("obstacle/reward"))
	      ob->set("obstacle/wuzhuang","done");

	// by snowcat
	// the following is a filter for 东海龙宫
	{
          string tmpstr;

          tmpstr = ob->query("family/family_name");
	  if (tmpstr == "龙宫")
	    ob->set("family/family_name","东海龙宫");

          tmpstr = ob->query("title");
	  if (tmpstr == "龙宫第二代弟子")
	    ob->set("title","东海龙宫第二代弟子");
	  if (tmpstr == "龙宫第三代弟子")
	    ob->set("title","东海龙宫第三代弟子");
	}

	// by snowcat
	// the following is a filter for relai reward
	{
	  if (ob->query("obstacle/reward") &&
	      ob->query("obstacle/mud_age") == 0)
	    ob->set("obstacle/mud_age", ob->query("mud_age"));
        }
	
    // don't check the following if is reconnecting.
    if(reconnect) return;

    // penalty on kaifeng quests when quitting.
    // randomly remove clouds.
    // mon 3/28/99
    colors=ob->query("quest/colors");
    j=sizeof(colors);
    if(j>1) {
       for(i=0;i<j/2;i++) {
         k=random(sizeof(colors));
         key=keys(colors)[k];
         map_delete(colors,key);
       }
       ob->set("quest/colors",colors);
    }

}
