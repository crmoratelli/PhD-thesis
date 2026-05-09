typedef struct vm_t {
	unsigned int id; /*VM ID*/
	unsigned int base_addr; /*Base address where the contiguous 
	mapping starts.*/
	unsigned int size;	/* VM size in bytes. */
	linkedlist_t vcpus; /*List of VCPUs associated to the VM.*/
	unsigned int os_type; /* OS executing in the VM.*/
	unsigned int ntlbent; /* Number of TLB entries. */
	unsigned int init;	/* Flag to indicate if the VM is 
	already initialized. */
	unsigned int fast_int; /* Interrupts market to the fast 
	interrupt delivery to this VM. */
	unsigned int apply_fast_int; /* Interrupts that can cause 
	preemption of this VM.*/
	unsigned int non_preemptable; /* Non preemptable VM. */

	struct tlbentry *tlbentries; /* TLB entries. Gives the 
	information of the valid memory regions for this VM. */
}vm_t;
