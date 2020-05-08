#ifndef _NODE_H_
#define _NODE_H_

typedef enum {
  NODE_ARGS,
  NODE_PAIR,
  NODE_VALUE,
  NODE_CFUNC,
  NODE_BLOCK,
  NODE_IDENT,
  NODE_LET,
  NODE_IF,
  NODE_EMIT,
  NODE_RETURN,
  NODE_BREAK,
  NODE_VAR,
  NODE_CONST,
  NODE_OP,
  NODE_CALL,
  NODE_IMPORT,
} node_type;

typedef struct {
  node_type type;
  squ_value value;
} node;

typedef struct {
  node* key;
  node* value;
} node_pair;

typedef squ_array node_array;

typedef struct {
  node* cond;
  node* stmt_seq;
  node* opt_else;
} node_if;

typedef struct {
  node* lhs;
  node* rhs;
} node_let;

typedef struct {
  node* lhs;
  char* op;
  node* rhs;
} node_op;

typedef struct {
  node* args;
  node* stmt_seq;
} node_block;

typedef struct {
  node* cond;
  node* ident;
  node* args;
  node* blk;
} node_call;

typedef struct {
  node* rv;
} node_return;

typedef struct {
  squ_id name;
} node_import;

extern node* node_value_new(node*);
extern node* node_array_new();
extern node* node_array_of(node*);
extern void node_array_add(node*, node*);
extern void node_array_free(node*);
extern node* node_pair_new(node*, node*);
extern node* node_map_new();
extern node* node_map_of(node*);
extern node* node_let_new(node*, node*);
extern node* node_op_new(char*, node*, node*);
extern node* node_block_new(node*, node*);
extern node* node_call_new(node*, node*, node*, node*);
extern node* node_double_new(squ_double);
extern node* node_string_new(squ_string);
extern node* node_string_len_new(squ_string, size_t);
extern node* node_if_new(node*, node*, node*);
extern node* node_return_new(node*);
extern node* node_import_new(squ_id);
extern node* node_break_new();
extern node* node_ident_new(squ_id);
extern squ_id node_ident_of(char*);
extern node* node_null();
extern node* node_true();
extern node* node_false();
extern void node_free(node*);

#endif /* _NODE_H_ */

