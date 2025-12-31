#[derive(Debug)]
pub struct HighScores {
    scores: Vec<u32>,
}

impl HighScores {
    pub fn new(scores: &[u32]) -> Self {
        Self {
            scores: scores.to_vec(),
        }
    }

    pub fn scores(&self) -> &[u32] {
        &self.scores[0..]
    }

    pub fn latest(&self) -> Option<u32> {
        self.scores.last().copied()
    }

    pub fn personal_best(&self) -> Option<u32> {
        let result = self.scores.iter().max();
        result.copied()
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        let mut sorted: Vec<u32> = self.scores.clone(); // Clone because I don't want to mutate the original
        sorted.sort_unstable_by(|a, b| b.cmp(a));
        sorted.iter().copied().take(3).collect()
    }
}
