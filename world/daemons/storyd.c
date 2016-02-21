// storyd.c

#include <ansi.h>

inherit F_DBASE;

private string *story_name = ({//选择故事
#if 1
        "laojun",
        "xiyou",
        "guanzhang",
        "nanji",
        "liandan",
	"caishen",
	"zhengxi",
	"zagang",
	"songdai",
	"niulang",
#endif
        "normal",
});

private object  running_story;
private mapping history;
private int step;
int filter_listener(object ob);

void ready_to_start()
{
        remove_call_out("process_story");
        call_out("start_story", 1800 + random(300));//间隔时间
//        call_out("start_story", 1 + random(1));//间隔时间
}
void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "事件精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "事件系统已经启动。\n");

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

void start_story()
{
        string name;
        object ob;
        int i;

        ready_to_start();
        CHANNEL_D->do_channel( this_object(), "sys", "事件系统开始选择事件。\n");

        for (i = 0; i < 12; i++)
        {
                name = story_name[random(sizeof(story_name))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);

                if (time() - history[name] > 14400 || name == "normal")
                {
                        history[name] = (int)time();
                        break;
                }
        }

        if (i >= 12) return;

        CHANNEL_D->do_channel( this_object(), "sys", "事件系统选择了事件(" + name + ")。\n");

        name = STORY_DIR + name;
        if (ob = find_object(name))
                destruct(ob);

        catch(ob = load_object(name));
        running_story = ob;

        if (! objectp(ob))
                return;

        step = 0;
        go_on_process(ob);
}

void process_story(object ob)
{
        mixed line;
	object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIY "【西行传说】 " NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
	}

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}

void give_gift(string gift, int amount, string msg)
{
        int i;
        object ob;
        object env;
        object *players;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                                
                        env = environment(ob);
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                }
                if (i >= 5) return;

                if (objectp(env))
                        tell_room(env, msg);
                for (i = 0; i < amount; i++)
                {
                        ob = new(gift);
                        ob->move(env);
                }
	        CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "赠品%s" NOR WHT "掉到了"
				HIC "%s" NOR WHT "(%O" NOR WHT ")。\n" NOR,
                               ob->name(), env->query("short"), env));
        }
}
