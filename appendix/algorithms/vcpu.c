typedef struct{
	unsigned int source_id; /*ID of the sender VM.*/
	unsigned int size; /*Size of the message.*/
	unsigned int message[MESSAGE_SZ]; /*Message.*/
} message_t;

/*Circular buffer.*/
typedef struct {
	unsigned int in; 
	unsigned int out;
	unsigned int num_messages;
	message_t message_list[MESSAGELIST_SZ];
} message_buffer_t;


typedef struct vcpu_t {  
	unsigned int id; /*VCPU ID.*/
	unsigned int rootcounter; /*counter register of the root 
	context.*/
	unsigned int offseTelapsedTime; /*Elapsed time to determine
	how long the VM is in the waiting queue.*/
	unsigned int gprshadowset; /*GRP shadow page.*/
	unsigned int cp0_registers[32][4]; /*CP0 registers*/
	unsigned int gp_registers[34];	/*CPU registers*/
	unsigned int guestclt2; /**/
	unsigned int pip; /* Indicates which interrupts are 
	allowed to the interrupt pass-through */
	vm_t *vm; /*VM data structure*/
	unsigned int pc; /*Program counter*/
	unsigned int sp; /* Stack pointer */
	unsigned int gp; /* Global pointer */
	message_buffer_t messages; /* Circular buffer.*/
}vcpu_t;
