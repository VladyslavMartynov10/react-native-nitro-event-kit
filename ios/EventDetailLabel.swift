//
//  EventDetailLabel.swift
//  NitroEventKit
//
//  Created by VLAD on 16.02.2025.
//

import UIKit

class EventDetailLabel: UILabel {
    override init(frame: CGRect) {
        super.init(frame: frame)
        configure()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    init(text: String, font: UIFont = .systemFont(ofSize: 16), textColor: UIColor = .gray, alignment: NSTextAlignment = .left, numberOfLines: Int = 1) {
        super.init(frame: .zero)
        
        self.text = text
        self.font = font
        self.textColor = textColor
        self.textAlignment = alignment
        self.numberOfLines = numberOfLines
        
        configure()
    }
    
    private func configure() {
        self.translatesAutoresizingMaskIntoConstraints = false
    }
}
