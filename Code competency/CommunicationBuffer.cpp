#include <iostream>
using namespace std;

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET& p)
{
	cin >> p.packet_no >> p.prior_level; // read packet_no, prior_level
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

/*new code*/

bool greaterOrEqual(PACKET* p1, PACKET* p2) {
	return (p1->prior_level >= p2->prior_level) ? true : false;
}

/*end new code*/

int Put_Packet_to_Buffer(PACKET& p)
{
	PACKET *pac;

	pac = new PACKET();

	*pac = p;

	/* old code
	last_packet->next = pac;
	last_packet = pac;
	*/
	
	/*new code*/
	PACKET* current = &buffer;
	
	while (current->next != (PACKET*)0 && greaterOrEqual(pac, current->next)) {
		current = current->next;
	}
				 
	if (current->next == (PACKET*)0) {
		current->next = pac;
		// current = pac;
	} else {
		pac->next = current->next;
		current->next = pac;
	}
	return SUCCESS;
				 
	/*end new code*/

}
int Get_Packet_from_Buffer(PACKET& p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	p = *buffer.next;
	delete buffer.next;

	buffer.next = p.next;
	
	return SUCCESS;
}

int main(void)
{
	int N;
	PACKET packet;

	cin >> N;	// read number of packet
	
	last_packet = &buffer;
	packet.next = NULL;

	for (int i = 0; i < N; i++)
	{
		Input_Packet(packet);
		Put_Packet_to_Buffer(packet);
	}
	
	// print packet processing order 
	while (Get_Packet_from_Buffer(packet) == SUCCESS)
	{
		cout << packet.packet_no << " ";
	}

	return 0;
}

