use crate::command::{Command, CommandType};

pub struct SetColor {
    pub r: u8,
    pub g: u8,
    pub b: u8,
}

impl SetColor {
    pub fn new(r: u8, g: u8, b: u8) -> Self {
        SetColor {
            r,
            g,
            // Slightly reduce the amount of blue, due to differences in color perception
            b: (b as f32 * 0.92) as u8,
        }
    }
}

impl Command for SetColor {
    fn command_id(&self) -> u8 {
        CommandType::SetColor as u8
    }

    fn to_bytes(&self) -> Vec<u8> {
        vec![self.r, self.g, self.b]
    }
}
