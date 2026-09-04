struct StockSpanner {
    // (price, span)
    stack: Vec<(i32, i32)>,
}

impl StockSpanner {
    fn new() -> Self {
        Self {
            stack: Vec::new(),
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut span = 1;

        while let Some(&(prev_price, prev_span)) = self.stack.last() {
            if prev_price <= price {
                span += prev_span;
                self.stack.pop();
            } else {
                break;
            }
        }

        self.stack.push((price, span));

        span
    }
}

fn main() {
    let mut stock_spanner = StockSpanner::new();

    let prices = vec![100, 80, 60, 70, 60, 75, 85];

    for price in prices {
        println!("{}", stock_spanner.next(price));
    }
}
