//
//  CloseButton.swift
//  NitroEventKit
//
//  Created by VLAD on 16.02.2025.
//

import UIKit

class CloseButton: UIButton {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        configure(with: "Done")
    }
    
    init(title: String, target: Any?, action: Selector) {
        super.init(frame: .zero)
        
        configure(with: title)
        
        addTarget(target, action: action, for: .touchUpInside)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func configure(with title: String) {
        setTitle(title, for: .normal)
        setTitleColor(.systemBlue, for: .normal)
        titleLabel?.font = .systemFont(ofSize: 16, weight: .medium)
        backgroundColor = .clear
        translatesAutoresizingMaskIntoConstraints = false
    }
}
