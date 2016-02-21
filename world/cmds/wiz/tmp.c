
#include <net/daemons.h>
#include <net/macros.h>

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size, nb, total=0;

	if( !find_object(DNS_MASTER) )
		return 0;

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return 0;

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++) {
                if(mud_list[muds[loop]]["MUDLIB"]=="A Journey to the West") {
			sscanf (mud_list[muds[loop]]["USERS"],"%d",nb);
			total += nb; 
		}
        }

	tell_object (me,chinese_number(total));
	return 1;
}


