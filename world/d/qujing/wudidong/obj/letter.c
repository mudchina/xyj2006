// letter.c

inherit ITEM;

void create()
{
	set_name("密函",({"mi han", "letter", "xin", "han", "mihan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","
致君访道之士：

    君得吾之密函，乃与本门有缘。望君能持此骷髅，替吾寻出本门
细作，报之于吾。此贼偷吾刀法秘笈一本，乃本洞镇洞至宝。吾得此
细作，自将其碎尸万段，食其心，饮其髓，方解吾心头之恨。事成之
日，君将秘笈为信物还吾，吾必收汝为徒，为洞中二代弟子。那时传
汝长生不老之无上心法，以振吾无底洞雄风！千万千万。

\t \t \t \t陷空山无底洞开山祖师玉鼠仙子。		   \n");
		set("unit","封");
		set("value", 0);
	}
}
