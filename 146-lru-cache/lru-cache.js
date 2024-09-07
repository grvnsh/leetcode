/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.cache = new Map();
    this.head = { key: 0, value: 0 };
    this.tail = { key: 0, value: 0 };
    this.head.next = this.tail;
    this.tail.prev = this.head;
};
/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (!this.cache.has(key)) {
        return -1;
    }
    const node = this.cache.get(key);
    this.moveToFront(node);
    return node.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.cache.has(key)) {
        const node = this.cache.get(key);
        node.value = value;
        this.moveToFront(node);
    } else {
        if (this.cache.size >= this.capacity) {
            const lruNode = this.tail.prev;
            this.removeNode(lruNode);
            this.cache.delete(lruNode.key);
        }
        const newNode = { key: key, value: value };
        this.cache.set(key, newNode);
        this.addToFront(newNode);
    }
};

LRUCache.prototype.moveToFront = function(node) {
    this.removeNode(node);
    this.addToFront(node);
};

LRUCache.prototype.addToFront = function(node) {
    node.prev = this.head;
    node.next = this.head.next;
    this.head.next.prev = node;
    this.head.next = node;
};

LRUCache.prototype.removeNode = function(node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */