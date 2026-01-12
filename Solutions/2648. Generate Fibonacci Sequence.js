/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0;
    let b = 1;
    while (true) {
        yield a;
        let temp = a + b;
        a = b;
        b = temp;
    }
};

const CallCount = 5;


 const gen = fibGenerator();
 for(let i = 0; i < CallCount; i++) {
     console.log(gen.next().value);
 }
