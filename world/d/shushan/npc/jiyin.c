inherit NPC;

int start_change(string arg);

void create()
{
       set_name("蜀山接引", ({"shi zhe"}));
       setup();
}

void init()
{
	::init();
  add_action("start_change", "change");
  
}

int start_change(string arg)
{
			int sword,force,spells,dodge;
			object who=this_player();
           if (who->query_temp("shushan/changed")=="done")
            return notify_fail("你已经转换完毕，是蜀山门下了。\n");
		    
			
if ((who->query("family/family_name")!="蜀山") && (who->query("family/family_name")!="蜀山剑派"))
			return notify_fail("你非蜀山门下，无法转换。\n");
			


			sword=(int)who->query_skill("songhe-sword", 1);
			force=(int)who->query_skill("shushan-force", 1);
			spells=(int)who->query_skill("xianfeng-spells", 1);
			dodge=(int)who->query_skill("zuixian-steps", 1);

                        who->delete_skill("songhe-sword");
                        who->delete_skill("shushan-force");
                        who->delete_skill("xianfeng-spells");
                        who->delete_skill("zuixian-steps");
			who->set_skill("shushan-jianfa",sword);
			who->set_skill("taoism",spells);
			who->set_skill("zixia-shengong",force);
			who->set_skill("sevensteps",dodge);
			who->map_skill("force", "zixia-shengong");
			who->map_skill("spells","taoism");
			who->set("family/family_name","蜀山剑派");
			command("smile");
			command("pat"+who->query("id"));
			command("say 转换完毕!");
			who->set_temp("shushan/changed","done");

return 1;
}
    
